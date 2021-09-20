#pragma once
#include <any>

#include "SyntaxToken.hpp"
#include "SyntaxFacts.hpp"
#include "Types.hpp"

namespace VSharp
{
	class Lexer
	{
		private:
			UInt64 _start;
			UInt64 _position;
			SyntaxKind _kind;
			std::any _value;

		public:
			explicit Lexer(const Char8* source) :
				_start(0), _position(0), _kind(SyntaxKind::BadToken), _value(nullptr), Source(source) {}
			
			Lexer() = default;

			~Lexer()
			{
				delete Source;
				delete GetFullTokenText();
			}

		public:
			const Char8* Source;
			[[nodiscard]] Char8 Current() const { return Peek(0); }
			[[nodiscard]] Char8 Next() const { return Peek(1); }

		public:
			static std::vector<SyntaxToken> CollectTokens(const Char8* source);

		private:
			// offset is signed because sometimes we'll need to peek backwards
			[[nodiscard]] Char8 Peek(const Int64 offset = 0) const;
			Char8 Advance();
			[[nodiscard]] const Char8* GetFullTokenText() const;

			void ScanStringOrCharLiteral();
			void ScanWhiteSpaces();
			void ScanNumericLiteral();
			void ScanIdentifierOrKeyword();
			
			[[nodiscard]] SyntaxToken ScanSyntaxToken();
	};
}
