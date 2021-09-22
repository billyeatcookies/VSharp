#include <vector>
#include <iostream>
#include <cassert>

#include "Lexer.hpp"
#include "..\Utilities\Utils.hpp"
#include "..\Syntax\SyntaxFacts.hpp"
#include "..\Syntax\SyntaxKind.hpp"
#include "..\Utilities\NumericParsing.hpp"

// TODO: Once Lexer is completed, handle diagnostics/errors/warnings to catch static analysis issues.

namespace VSharp::Frontend
{
	std::vector<Syntax::SyntaxToken> Lexer::CollectTokens(const std::wstring& source)
	{
		Lexer lexer(source);
		std::vector<Syntax::SyntaxToken> tokens{};
		Syntax::SyntaxToken token{};

		do
		{
			token = lexer.ScanSyntaxToken();
			if (token.Kind != Syntax::SyntaxKind::WhiteSpaceToken && 
				token.Kind != Syntax::SyntaxKind::BadToken)
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
			case InvalidChar():
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
				std::wcerr << L"unexpected token '" << Current() << L"': " << _position << std::endl;
				Advance();
				break;
		}

		const std::wstring text = GetFullTokenText();
		return Syntax::SyntaxToken(_kind, _position, text, _value);
	}

	std::wstring Lexer::GetFullTokenText() const
	{
		const UInt32 length = _position - _start;
		return Source.substr(_start, length);
	}

	Char16 Lexer::Peek(const Int32 offset) const
	{
		// the index should never be negative, but if we take a negative offset,
		// it means we want to peek to previous characters 
		const UInt32 index = _position + offset;
		if (index >= Source.length())
		{
			return InvalidChar();
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
		// TODO(2): such as 'UI64' so people can use "12UI64" to
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

		const UInt32 length = _position - _start;
		const std::wstring text = Source.substr(_start, length);

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

		if (hasDecimal || Current() == 'F')
		{
			// Validate float
			if (Current() == 'F' && Next() == '3')
			{
				Advance();
				Advance();
				if (Current() == '2')
				{
					Advance();
					const std::tuple<Float32, bool> result = Utilities::TryParseF32(text);
					if (!std::get<1>(result))
					{
						std::cerr << "invalid number" << std::endl;
						return;
					}
					_value = std::get<0>(result);
					_kind = Syntax::SyntaxKind::Float32LiteralToken;
				}
			}
			else if (Current() == 'F' && Next() == '6')
			{
				Advance();
				Advance();
				if (Current() == '4')
				{
					Advance();
					const std::tuple<Float64, bool> result = Utilities::TryParseF64(text);
					if (!std::get<1>(result))
					{
						std::cerr << "invalid number" << std::endl;
						return;
					}
					_value = std::get<0>(result);
					_kind = Syntax::SyntaxKind::Float64LiteralToken;

				}
			}
			else
			{
				ValidateDecimalLiteral(text);
			}
		}
		else if (Current() == 'U' || Current() == 'I')
		{
			// Unsigned integer suffixes "UI64" etc
			if (Current() == 'U' && Next() == 'I')
			{
				const std::tuple<UInt64, bool> result = Utilities::TryParseUI64(text);
				if (!std::get<1>(result))
				{
					std::cerr << "invalid number" << std::endl;
					return;
				}

				const UInt64 value = std::get<0>(result);

				Advance();
				Advance();
				if (Current() == '8')
				{
					Advance();
					
					_value = static_cast<UInt8>(value);
					_kind = Syntax::SyntaxKind::UInt8LiteralToken;
				}
				else if (Current() == '1' && Next() == '6')
				{
					Advance();
					Advance();
					_value = static_cast<UInt16>(value);
					_kind = Syntax::SyntaxKind::UInt16LiteralToken;
				}
				else if (Current() == '3' && Next() == '2')
				{
					Advance();
					Advance();
					_value = static_cast<UInt32>(value);
					_kind = Syntax::SyntaxKind::UInt32LiteralToken;
				}
				else if (Current() == '6' && Next() == '4')
				{
					Advance();
					Advance();
					_value = static_cast<UInt64>(value);
					_kind = Syntax::SyntaxKind::UInt64LiteralToken;
				}
			}
			// Signed integer suffixes "I64" etc
			else if (Current() == 'I')
			{
				const std::tuple<Int64, bool> result = Utilities::TryParseI64(text);
				if (!std::get<1>(result))
				{
					std::cerr << "invalid number" << std::endl;
					return;
				}

				const UInt64 value = std::get<0>(result);

				Advance();
				if (Current() == '8')
				{
					Advance();
					_value = static_cast<Int8>(value);
					_kind = Syntax::SyntaxKind::Int8LiteralToken;
				}
				else if (Current() == '1' && Next() == '6')
				{
					Advance();
					Advance();
					_value = static_cast<Int16>(value);
					_kind = Syntax::SyntaxKind::Int16LiteralToken;
				}
				else if (Current() == '3' && Next() == '2')
				{
					Advance();
					Advance();
					_value = static_cast<Int32>(value);
					_kind = Syntax::SyntaxKind::Int32LiteralToken;
				}
				else if (Current() == '6' && Next() == '4')
				{
					Advance();
					Advance();
					
					_value = static_cast<UInt64>(value);
					_kind = Syntax::SyntaxKind::Int64LiteralToken;
				}
			}
			else
			{
				ValidateIntegerLiteral(text);
			}
		}
	}

	void Lexer::ValidateDecimalLiteral(const std::wstring& text)
	{
		const std::tuple<Float64, bool> result = Utilities::TryParseF64(text);
		if (!std::get<1>(result))
		{
			std::cerr << "invalid number" << std::endl;
			return;
		}

		const Float64 value = std::get<0>(result);
		if (value >= static_cast<Float64>(Float32Min) && value <= static_cast<Float64>(Float32Max))
		{
			_value = static_cast<Float32>(value);
			_kind = Syntax::SyntaxKind::Float32LiteralToken;
		}
		else if (value >= Float64Min && value <= Float64Max)
		{
			_value = value;
			_kind = Syntax::SyntaxKind::Float64LiteralToken;
		}
	}

	void Lexer::ValidateIntegerLiteral(const std::wstring& text)
	{
		const std::tuple<UInt64, bool> result = Utilities::TryParseUI64(text);
		if (!std::get<1>(result))
		{
			std::cerr << "invalid number" << std::endl;
			return;
		}

		const UInt64 value = std::get<0>(result);
		if (value <= Int32Max)
		{
			_kind = Syntax::SyntaxKind::Int32LiteralToken;
			_value = static_cast<Int32>(value);
		}
		else if (value <= UInt32Max)
		{
			_kind = Syntax::SyntaxKind::UInt32LiteralToken;
			_value = static_cast<UInt32>(value);
		}
		else if (value <= Int64Max)
		{
			_kind = Syntax::SyntaxKind::Int64LiteralToken;
			_value = static_cast<Int64>(value);
		}
		else
		{
			_kind = Syntax::SyntaxKind::UInt64LiteralToken;
			_value = value;
		}
	}


	// TODO: Support escapes
	void Lexer::ScanStringOrCharLiteral()
	{
		const Char16 quoteChar = Current();
		assert(quoteChar == '\'' || quoteChar == '"');
		Advance();

		std::wstring buffer;
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

		const UInt32 length = _position - _start;
		//const Char8* text = Utilities::Substring(Source, _start, length);
		const std::wstring text = Source.substr(_start, length);
		// Will either be a reserved keyword or IdentifierToken for user defined tokens
		_kind = Syntax::LookupKeyword(text);
	}

	Char16 Lexer::Advance()
	{
		if (_position == Source.length())
		{
			return Source[_position];
		}

		_position++;
		return Source[_position];
	}
}
