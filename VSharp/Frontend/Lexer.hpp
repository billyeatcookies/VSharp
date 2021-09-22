#pragma once
#include <any>

#include "..\Syntax\SyntaxToken.hpp"
#include "..\Syntax\SyntaxFacts.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Frontend
{
	using namespace Types;

	class Lexer
	{
		private:
			// The start position of a "lexeme" or "token". If the Lexer was lexing "float32 foo = 42.0;",
			// and the current token was "foo" the start position would be 9. 
			UInt32 _start;

			// The current position of the text the Lexer is at. If the Lexer was lexing "float32 foo = 42.0f;",
			// and the lexer was at "foo"s first 'o', the position would be 10.  
			UInt32 _position;

			// The kind of the current token, Float32LiteralToken, Int32LiteralToken, etc. This is used for future reference
			// during compilation/emission, we need to know which special type to emit.
			Syntax::SyntaxKind _kind;

			// TODO: I'm not necessarily a fan of this currently, we need a better method of tracking the current "type" of the token
			// This tracks the current value of a token if this is a Float32LiteralToken it would be a 'Types::Float32' and you'd use 
			// std::any_cast<Types::Float32> to retrieve the value, this is safe since we KNOW the type by checking Syntax::SyntaxKind
			// during binding/CIL emission.
			std::any _value;

		public:
			// Creates a new Lexer from a source text input, this will be from a REPL or file, the Lexer doesn't care where it's from
			explicit Lexer(std::wstring source) :
				_start(0), _position(0), _kind(Syntax::SyntaxKind::BadToken), _value(nullptr), Source(std::move(source)) {}

		public:
			// The source text to keep track of during the Lexer phase, this is used for Peeking the current character and validating lexemes
			const std::wstring Source;
			[[nodiscard]] static constexpr Char16 InvalidChar() { return -1; }

			// The current character the lexer is examining, decimals, numbers, identifiers, etc...
			[[nodiscard]] Char16 Current() const { return Peek(0); }
			// The next token in line for the Lexer, this always points 1 position AHEAD of Current()
			[[nodiscard]] Char16 Next() const { return Peek(1); }

		public:
			// TODO: We need a better method for also collecting diagnostics/errors/warnings when we get the tokens for parse phase
			// This method will collect all valid tokens and return a list of them, regardless of errors, attempting to emit as many
			// valid syntax errors as possible, while avoiding cascading errors.
			[[nodiscard]] static std::vector<Syntax::SyntaxToken> CollectTokens(const std::wstring& source);

		private:
			// Checks X characters ahead/behind in the Lexer, offset isn't Types::UInt64 because sometimes we'll use Peek(-1)
			// to check a character behind us, an unsigned int would error out. 
			[[nodiscard]] Char16 Peek(const Int32 offset = 0) const; // offset is signed because sometimes we'll need to peek backwards

			// Advances 1 in the source text and returns the character the Lexer is currently sitting on after advancing
			Char16 Advance();

			// TODO: This method name doesn't properly explain what it does
			// Gets a tokens full text, from _start to _position. If the token was Float32LiteralToken the full text might be "42.42",
			// an identifier might be "foobar", but without the quotes obviously. This will also get a string/chars raw text. If a literal
			// string was `"hello world"` it would return `hello world`. This always ensures a tokens true value.
			[[nodiscard]] std::wstring GetFullTokenText() const;

			// These smaller incremental scanners prefix with "Scan" because they aren't full blow Lexers, but rather "scan" a select window of text

			// This will scan a char or string literal, being something like 'o' or "hello world". This also takes character/string literal escapes
			// into account '\u0000', '\r', or "hello\nworld", and stores the raw data. 
			void ScanStringOrCharLiteral();

			// This is technically a misleading name because it rather SKIPS whitespace, since we aren't currently storing whitespace tokens, we technically
			// assign _kind to Syntax::SyntaxKind::WhiteSpaceToken at the end of this method, but we skip don't add whitespace tokens in CollectTokens
			void ScanWhiteSpaces();

			// Handles all integer and decimal literals, currently suffixes like "42.2f64" or "69ui64" for validating literals and assigning them to their correct size.
			void ScanNumericLiteral();

			// Handles any token that starts with [a-z], [A-Z], or [_]. An identifier may contain numbers, but only after the first character
			void ScanIdentifierOrKeyword();

			// The base tokenizer that starts the process. Basically a massive switch token that goes down all the valid characters
			[[nodiscard]] Syntax::SyntaxToken ScanSyntaxToken();
	};
}
