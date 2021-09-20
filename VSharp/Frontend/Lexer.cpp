#include <vector>
#include <iostream>

#include "Lexer.hpp"
#include "..\Utilities\Utils.hpp"
#include "..\Syntax\SyntaxFacts.hpp"

namespace VSharp::Frontend
{
	std::vector<Syntax::SyntaxToken> Lexer::CollectTokens(const Types::Char8* source)
	{
		Lexer lexer(source);
		std::vector<Syntax::SyntaxToken> tokens{};
		Syntax::SyntaxToken token{};

		do
		{
			token = lexer.ScanSyntaxToken();
			if (token.Kind != Syntax::SyntaxKind::BadToken)
			{
				tokens.push_back(token);
			}
		} while (token.Kind != Syntax::SyntaxKind::EndOfFileToken);

		return tokens;
	}

	Syntax::SyntaxToken Lexer::ScanSyntaxToken()
	{
		_start = _position;
		_value = nullptr;
		_kind = Syntax::SyntaxKind::BadToken;

		switch (Current())
		{
			case '\0':
				_kind = Syntax::SyntaxKind::EndOfFileToken;
				break;
			case '.':
				_kind = Syntax::SyntaxKind::DotToken;
				Advance();
				break;
			case ',':
				_kind = Syntax::SyntaxKind::CommaToken;
				Advance();
				break;
			case '(':
				_kind = Syntax::SyntaxKind::OpenParenToken;
				Advance();
				break;
			case ')':
				_kind = Syntax::SyntaxKind::CloseParenToken;
				Advance();
				break;
			case '{':
				_kind = Syntax::SyntaxKind::OpenBraceToken;
				Advance();
				break;
			case '}':
				_kind = Syntax::SyntaxKind::CloseBraceToken;
				Advance();
				break;
			case '[':
				_kind = Syntax::SyntaxKind::OpenBracketToken;
				Advance();
				break;
			case ']':
				_kind = Syntax::SyntaxKind::CloseBracketToken;
				Advance();
				break;
			case ':':
				_kind = Syntax::SyntaxKind::ColonToken;
				Advance();
				break;
			case ';':
				_kind = Syntax::SyntaxKind::SemicolonToken;
				Advance();
				break;
			case '?':
				_kind = Syntax::SyntaxKind::QuestionMarkToken;
				Advance();
				break;
			case '^':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::CaretEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::CaretToken;
						break;
				}
				break;
			case '~':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::TildeEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::TildeToken;
						break;
				}
				break;
			case '+':
				Advance();
				switch (Current())
				{
					case '+':
						_kind = Syntax::SyntaxKind::PlusPlusToken;
						Advance();
						break;
					case '=':
						_kind = Syntax::SyntaxKind::PlusEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::PlusToken;
						break;
				}
				break;
			case '-':
				Advance();
				switch (Current())
				{
				case '-':
					_kind = Syntax::SyntaxKind::MinusMinusToken;
					Advance();
					break;
				case '=':
					_kind = Syntax::SyntaxKind::MinusEqualsToken;
					Advance();
					break;
				default:
					_kind = Syntax::SyntaxKind::MinusToken;
					break;
				}
				break;
			case '/':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::FSlashEqualsToken;
						Advance();
						break;
					// TODO: Comments
					default:
						_kind = Syntax::SyntaxKind::FSlashToken;
						break;
				}
				break;
			case '*':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::AsteriskEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::MinusToken;
						break;
				}
				break;
			case '%':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::PercentEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::PercentToken;
						break;
				}
				break;
			case '=':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::EqualsEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::EqualsToken;
						break;
				}
				break;
			case '>':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::GreaterEqualsToken;
						Advance();
						break;
					case '>':
						Advance();
						if (Current() == '=')
						{
							_kind = Syntax::SyntaxKind::GreaterGreaterEqualsToken;
							Advance();
						}
						else
						{
							_kind = Syntax::SyntaxKind::GreaterGreaterToken;
						}
						break;
					default:
						_kind = Syntax::SyntaxKind::GreaterToken;
						break;
				}
				break;
			case '<':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::LessEqualsToken;
						Advance();
						break;
					case '<':
						Advance();
						if (Current() == '=')
						{
							_kind = Syntax::SyntaxKind::LessLessEqualsToken;
							Advance();
						}
						else
						{
							_kind = Syntax::SyntaxKind::LessLessToken;
						}
						break;
					default:
						_kind = Syntax::SyntaxKind::LessToken;
						break;
				}
				break;
			case '!':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::BangEqualsToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::BangToken;
						break;
				}
				break;
			case '|':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::PipeEqualsToken;
						Advance();
						break;
					case '|':
						_kind = Syntax::SyntaxKind::PipePipeToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::PipeToken;
						break;
				}
				break;
			case '&':
				Advance();
				switch (Current())
				{
					case '=':
						_kind = Syntax::SyntaxKind::AmpersandEqualsToken;
						Advance();
						break;
					case '&':
						_kind = Syntax::SyntaxKind::AmpersandAmpersandToken;
						Advance();
						break;
					default:
						_kind = Syntax::SyntaxKind::AmpersandToken;
						break;
				}
				break;
			case '"':
			case '\'':
				ScanStringOrCharLiteral();
				break;
			default:
				if (Utilities::IsWhiteSpace(Current()))
				{
					ScanWhiteSpaces();
				}
				if (Utilities::IsDigit(Current()))
				{
					ScanNumericLiteral();
				}
				// check if it's valid a-z, A-Z or contains an underscore _
				if (Utilities::IsAlpha(Current()))
				{
					ScanIdentifierOrKeyword();
				}

				// We've clearly entered a token that isn't handled
				std::cerr << "unexpected token '" << Current() << "'" << std::endl;
				_text = Current();
				Advance();
				break;
		}

		_text = GetFullTokenText();
		return Syntax::SyntaxToken(_kind, _position, _text.c_str(), _value);
	}

	const Types::Char8* Lexer::GetFullTokenText() const
	{

		const unsigned int length = _position - _start;
		const Types::Char8* text = Utilities::Substring(Source, _start, length);
		return text;
	}

	Types::Char8 Lexer::Peek(const Types::Int64 offset) const
	{
		// the index should never be negative, but if we take a negative offset,
		// it means we want to peek to previous characters 
		const Types::UInt64 index = _position + offset;
		if (index >= std::strlen(Source))
		{
			return '\0';
		}

		return Source[index];
	}

	void Lexer::ScanWhiteSpaces()
	{
		while (Utilities::IsWhiteSpace(Current()))
		{
			Advance();
		}
	}

	// TODO: Fully support floats, and assign correct types
	void Lexer::ScanNumericLiteral()
	{
		while (Utilities::IsDigit(Current()))
		{
			Advance();
		}

		if (Current() == '.' && Utilities::IsDigit(Next()))
		{
			Advance();
			while (Utilities::IsDigit(Current()))
			{
				Advance();
			}
		}

		_text = GetFullTokenText();
		_value = atof(_text.c_str()); // this parses to double
		_kind = Syntax::SyntaxKind::Float64LiteralToken;
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

		_kind = quoteChar == '"' ? Syntax::SyntaxKind::StringLiteralToken : Syntax::SyntaxKind::CharLiteralToken;

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

			_text = buffer[0];
			_value = buffer[0];
		}
	}

	void Lexer::ScanIdentifierOrKeyword()
	{
		while (Utilities::IsAlphanumeric(Current()))
		{
			Advance();
		}

		const Types::UInt64 length = _position - _start;
		_text = Utilities::Substring(Source, _start, length);

		// Will either be a reserved keyword or IdentifierToken for user defined tokens
		_kind = Syntax::LookupKeyword(_text.c_str());
	}

	Types::Char8 Lexer::Advance()
	{
		if (_position == std::strlen(Source))
		{
			return Source[_position];
		}

		_position++;
		return Source[_position];
	}
}