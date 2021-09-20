#pragma once
#include "SyntaxToken.hpp"
#include "Types.hpp"

namespace VSharp
{
	class Lexer
	{
		private:
			UInt64 _start;
			UInt64 _position;
			SyntaxKind _kind;
			void* _value;

		public:
			explicit Lexer(const Char8* source) :
				_start(0), _position(0), _kind(SyntaxKind::BadToken), _value(nullptr), Source(source) {}
			Lexer() = default;
			~Lexer() = default;

		public:
			const Char8* Source;
			Char8 Current() const { return Peek(0); }
			Char8 Next() const { return Peek(1); }

		public:
			//static std::vector<SyntaxToken> CollectTokens(const Char8* source);
			static SyntaxToken* CollectTokens(const Char8* source);

		private:
			// offset is signed because sometimes we'll need to peek backwards
			Char8 Peek(const Int64 offset = 0) const;
			Char8 Advance();
			const Char8* GetFullTokenText() const;

			void ScanWhiteSpaces();
			void ScanNumericLiteral();
			void ScanIdentifierOrKeyword();
			
			SyntaxToken ScanSyntaxToken();
	};
}
