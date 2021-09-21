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
			case ' ':
			case '\r':
			case '\n':
			case '\t':
				ScanWhiteSpaces();
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				ScanNumericLiteral();
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
				ScanIdentifierOrKeyword();
				break;
			default:
				// We've clearly entered a token that isn't handled
				std::cerr << "unexpected token '" << Current() << "': " << _position << std::endl;
				Advance();
				break;
		}

		const Types::Char8* text = GetFullTokenText();
		return Syntax::SyntaxToken(_kind, _position, text, _value);
	}

	const Types::Char8* Lexer::GetFullTokenText() const
	{

		const Types::UInt64 length = _position - _start;
		return Utilities::Substring(Source, _start, length); // Source.substr(_start, length);
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

		_kind = Syntax::SyntaxKind::WhiteSpaceToken;
	}

	void Lexer::ScanNumericLiteral()
	{
		// TODO(1): Fully support floats, and assign correct types
		// TODO(2): Fully support binary, hex, and literal suffixes 
		// TODO(2): such as 'ui64' so people can use "12ui64" to
		// TODO(2): fully express intent when assigning with "var"

		bool hasSeparator = false;
		bool hasDecimal = false;
		bool hasMultipleDecimals = false;

		while (Utilities::IsDigit(Current()) ||
			   Current() == '_' && Utilities::IsDigit(Next()) ||
			   Current() == '.' && Utilities::IsDigit(Next()))
		{
			if (!hasSeparator && Current() == '_')
			{
				hasSeparator = true;
			}

			if (Current() == '.')
			{
				if (hasDecimal)
				{
					hasMultipleDecimals = true;
				}
				hasDecimal = true;
			}

			Advance();
		}

		const Types::UInt64 length = _position - _start;
		const Types::Char8* text = Utilities::Substring(Source, _start, length);

		if (text[0] == '_')
		{
			std::cerr << "invalid number";
			return;
		}

		if (hasMultipleDecimals)
		{
			std::cerr << "invalid number";
			return;
		}

		if (hasDecimal)
		{
			Types::Float64 value;
			try
			{
				value = strtod(text, nullptr);
			}
			catch (...)
			{
				std::cerr << "invalid number";
				return;
			}
			if (value >= Types::Float32Min && value <= Types::Float32Max)
			{
				_value = static_cast<Types::Float32>(value);
				_kind = Syntax::SyntaxKind::Float32LiteralToken;
			}
			else if (value >= Types::Float64Min && value <= Types::Float64Max)
			{
				_value = value;
				_kind = Syntax::SyntaxKind::Float64LiteralToken;
			}
		}
		else
		{
			Types::UInt64 value;
			try
			{
				value = std::stoull(text);
			}
			catch (...)
			{
				std::cerr << "invalid number";
				return;
			}
			if (value <= Types::Int32Max)
			{
				_kind = Syntax::SyntaxKind::Int32LiteralToken;
				_value = static_cast<Types::Int32>(value);
			}
			else if (value <= Types::UInt32Max)
			{
				_kind = Syntax::SyntaxKind::UInt32LiteralToken;
				_value = static_cast<Types::UInt32>(value);
			}
			else if (value <= Types::Int64Max)
			{
				_kind = Syntax::SyntaxKind::Int64LiteralToken;
				_value = static_cast<Types::Int64>(value);
			}
			// this could be a regular "else" statement, but I think it's better to explicitly state intention
			else if (value <= Types::UInt64Max)
			{
				_kind = Syntax::SyntaxKind::UInt64LiteralToken;
				_value = value;
			}
		}

		/*while (Utilities::IsDigit(Current()))
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

		const Types::Char8* text = GetFullTokenText();
		_value = strtod(text, nullptr);
		_kind = Syntax::SyntaxKind::Float64LiteralToken;
		*/
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
		const Types::Char8* text = Utilities::Substring(Source, _start, length);
		// Will either be a reserved keyword or IdentifierToken for user defined tokens
		_kind = Syntax::LookupKeyword(text);
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