#include "Lexer.hpp"
#include <vector>
#include <iostream>
#include "Utils.hpp"

namespace VSharp
{
	//std::vector<SyntaxToken> Lexer::CollectTokens(const Char8* source)
	SyntaxToken* Lexer::CollectTokens(const Char8* source)
	{
		Lexer lexer(source);
		std::vector<SyntaxToken> tokens{};
		SyntaxToken token{};

		do
		{
			token = lexer.ScanSyntaxToken();
			if (token.Kind != SyntaxKind::BadToken)
			{
				tokens.push_back(token);
			}
		} while (token.Kind != SyntaxKind::EndOfFileToken);

		SyntaxToken* arrTokens = new SyntaxToken[tokens.size()];
		std::copy(tokens.begin(), tokens.end(), arrTokens);
		return arrTokens;
	}

	SyntaxToken Lexer::ScanSyntaxToken()
	{
		_start = _position;
		_value = nullptr;
		_kind = SyntaxKind::BadToken;

		switch (Current())
		{
			case '\0':
				_kind = SyntaxKind::EndOfFileToken;
				break;
			case '+':
				_kind = SyntaxKind::PlusToken;
				Advance();
				break;
			case '-':
				_kind = SyntaxKind::MinusToken;
				Advance();
				break;
			case '/':
				_kind = SyntaxKind::FSlashToken;
				Advance();
				break;
			case '*':
				_kind = SyntaxKind::AsteriskToken;
				Advance();
				break;
			default:
				if (IsWhiteSpace(Current()))
				{
					ScanWhiteSpaces();
				}
				if (IsDigit(Current()))
				{
					ScanNumericLiteral();
				}
				// check if it's valid a-z, A-Z or contains an underscore _
				if (IsAlpha(Current()))
				{
					
				}
				else
				{
					std::cout << Current();
					Advance();
				}
				break;
		}

		const Char8* text = GetFullTokenText();
		return SyntaxToken(_kind, _position, text, _value);
	}

	const Char8* Lexer::GetFullTokenText() const
	{
		const unsigned int length = _position - _start;
		/*if (length > Source.length())
		{
			length = Source.length();
		}*/

		return VSharp::Substring(Source, _start, length);
	}

	Char8 Lexer::Peek(const Int64 offset) const
	{
		// the index should never be negative, but if we take a negative offset,
		// it means we want to peek to previous characters 
		const UInt64 index = _position + offset;
		if (index >= std::strlen(Source))
		{
			return '\0';
		}

		return Source[index];
	}

	void Lexer::ScanWhiteSpaces()
	{
		while (IsWhiteSpace(Current()))
		{
			Advance();
		}
	}

	void Lexer::ScanNumericLiteral()
	{
		while (IsDigit(Current()))
		{
			Advance();
		}

		if (Current() == '.' && IsDigit(Next()))
		{
			Advance();
			while (IsDigit(Current()))
			{
				Advance();
			}
		}

		const Char8* text = GetFullTokenText();
		Float64 value = atof(text);
		_value = &value;

		_kind = SyntaxKind::NumericLiteralToken;
	}

	void Lexer::ScanIdentifierOrKeyword()
	{
		while (IsAlphanumeric(Current()))
		{
			Advance();
		}
	}

	Char8 Lexer::Advance()
	{
		if (_position == std::strlen(Source))
		{
			return Source[_position];
		}

		_position++;
		return Source[_position];
	}
}