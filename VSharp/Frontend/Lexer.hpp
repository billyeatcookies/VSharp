#pragma once
#include <any>

#include "..\Syntax\SyntaxToken.hpp"
#include "..\Syntax\SyntaxFacts.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Frontend
{
	class Lexer
	{
		private:
			Types::UInt64 _start;
			Types::UInt64 _position;
			Syntax::SyntaxKind _kind;
			std::any _value;

		public:
			explicit Lexer(const Types::Char8* source) :
				_start(0), _position(0), _kind(Syntax::SyntaxKind::BadToken), _value(nullptr), Source(source) {}
			
			Lexer() = default;

			~Lexer()
			{
				delete Source;
				delete GetFullTokenText();
			}

		public:
			const Types::Char8* Source;
			[[nodiscard]] Types::Char8 Current() const { return Peek(0); }
			[[nodiscard]] Types::Char8 Next() const { return Peek(1); }

		public:
			static std::vector<Syntax::SyntaxToken> CollectTokens(const Types::Char8* source);

		private:
			// offset is signed because sometimes we'll need to peek backwards
			[[nodiscard]] Types::Char8 Peek(const Types::Int64 offset = 0) const;
			Types::Char8 Advance();
			[[nodiscard]] const Types::Char8* GetFullTokenText() const;

			void ScanStringOrCharLiteral();
			void ScanWhiteSpaces();
			void ScanNumericLiteral();
			void ScanIdentifierOrKeyword();
			
			[[nodiscard]] Syntax::SyntaxToken ScanSyntaxToken();
	};
}
