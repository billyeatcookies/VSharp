#include "Lexer.hpp"
#include <vector>
#include <iostream>
#include "Utils.hpp"
#include "SyntaxFacts.hpp"

namespace VSharp
{
	std::vector<SyntaxToken> Lexer::CollectTokens(const Char8* source)
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

		return tokens;
	}

	// 12.12 + 12.12
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
			case '(':
				_kind = SyntaxKind::OpenParenToken;
				Advance();
				break;
			case ')':
				_kind = SyntaxKind::CloseParenToken;
				Advance();
				break;
			case '{':
				_kind = SyntaxKind::OpenBraceToken;
				Advance();
				break;
			case '}':
				_kind = SyntaxKind::CloseBraceToken;
				Advance();
				break;
			case ':':
				_kind = SyntaxKind::ColonToken;
				Advance();
				break;
			case ';':
				_kind = SyntaxKind::SemicolonToken;
				Advance();
				break;
			case '?':
				_kind = SyntaxKind::QuestionMarkToken;
				Advance();
				break;
			case '+':
				Advance();
				switch (Current())
				{
					case '+':
						_kind = SyntaxKind::PlusPlusToken;
						Advance();
						break;
					case '=':
						_kind = SyntaxKind::PlusEqualsToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::PlusToken;
						break;
				}
				break;
			case '-':
				Advance();
				switch (Current())
				{
				case '-':
					_kind = SyntaxKind::MinusMinusToken;
					Advance();
					break;
				case '=':
					_kind = SyntaxKind::MinusEqualsToken;
					Advance();
					break;
				default:
					_kind = SyntaxKind::MinusToken;
					break;
				}
				break;
			case '/':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::FSlashEqualsToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::FSlashToken;
						break;
				}
				break;
			case '*':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::AsteriskEqualsToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::MinusToken;
						break;
				}
				break;
			case '%':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::PercentEqualsToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::PercentToken;
						break;
				}
				break;
			case '=':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::EqualsEqualsToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::EqualsToken;
						break;
				}
				break;
			case '>':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::GreaterEqualsToken;
						Advance();
						break;
					case '>':
						_kind = SyntaxKind::GreaterGreaterToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::GreaterToken;
						break;
				}
				break;
			case '<':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::LessEqualsToken;
						Advance();
						break;
					case '<':
						_kind = SyntaxKind::LessLessToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::LessToken;
						break;
				}
				break;
			case '!':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::BangEqualsToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::BangToken;
						break;
				}
				break;
			case '|':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::PipeEqualsToken;
						Advance();
						break;
					case '|':
						_kind = SyntaxKind::PipePipeToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::PipeToken;
						break;
				}
				break;
			case '&':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = SyntaxKind::AmpersandEqualsToken;
						Advance();
						break;
					case '&':
						_kind = SyntaxKind::AmpersandAmpersandToken;
						Advance();
						break;
					default:
						_kind = SyntaxKind::AmpersandToken;
						break;
				}
				break;
			case '"':
			case '\'':
				ScanStringOrCharLiteral();
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
					ScanIdentifierOrKeyword();
				}
				std::cout << Current();
				Advance();
				break;
		}

		const Char8* text = GetFullTokenText();
		return SyntaxToken(_kind, _position, text, _value);
	}

	const Char8* Lexer::GetFullTokenText() const
	{

		const unsigned int length = _position - _start;
		const Char8* text = VSharp::Substring(Source, _start, length);
		return text;
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

	// TODO: Fully support floats, and assign correct types
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
		_value = atof(text); // this parses to double
		_kind = SyntaxKind::Float64LiteralToken;
	}

	// TODO: Support escapes
	void Lexer::ScanStringOrCharLiteral()
	{
		const char quoteChar = Current();
		Advance();

		std::string buffer;
		bool done = false;
		while (!done)
		{
			switch (Current())
			{
				case '\0':
				case '\r':
				case '\n':
					std::cerr << "unterminated string literal" << std::endl;
					done = true;
					break;
				case '\'':
				case '"':
					if (Next() == quoteChar)
					{
						buffer += Current();
						Advance();
						Advance();
					}
					else
					{
						Advance();
						done = true;
					}
					break;
				default:
					buffer += Current();
					Advance();
					break;
			}
		}

		_kind = quoteChar == '"' ? SyntaxKind::StringLiteralToken : SyntaxKind::CharLiteralToken;

		if (quoteChar == '"')
		{
			_value = buffer;
		}
		else
		{
			if (buffer.length() > 1)
			{
				if (buffer.empty())
				{
					std::cerr << "empty character constant";
				}
				else
				{
					std::cerr << "invalid character constant";
				}
			}

			_value = buffer[0];
		}
	}

	void Lexer::ScanIdentifierOrKeyword()
	{
		while (IsAlphanumeric(Current()))
		{
			Advance();
		}

		const UInt64 length = _position - _start;
		const Char8* text = Substring(Source, _start, length);
		// Will either be a reserved keyword or IdentifierToken for user defined tokens
		_kind = LookupKeyword(text);
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