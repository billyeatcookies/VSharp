#pragma once
#include <unordered_map>

#include "..\Utilities\Types.hpp"
#include "SyntaxKind.hpp"

namespace VSharp::Syntax
{
	[[nodiscard]] static const Types::Char8* LookupMemberName(const SyntaxKind kind);
	[[nodiscard]] static SyntaxKind LookupKeyword(const Types::Char8* input);

	[[nodiscard]] static const Types::Char8* GetText(const SyntaxKind kind)
	{
		// TODO: I'm not sure if I want this to also be an unordered_map yet since it's also sharing reserved keywords 
		
		// DO NOT handle a token that doesn't represent a set of text on it's own,
		// ex: IdentifierToken, BadToken, Float32Literal -- these tokens are used to
		// compliment the fully constructed token and provide extra info. By keeping cases
		// as short as possible we can keep this file size as small as possible... hopefully
		switch (kind)
		{
			case SyntaxKind::ColonToken:
				return ":";
			case SyntaxKind::SemicolonToken:
				return ";";
			case SyntaxKind::DotToken:
				return ".";
			case SyntaxKind::CommaToken:
				return ",";
			case SyntaxKind::OpenParenToken:
				return "(";
			case SyntaxKind::CloseParenToken:
				return ")";
			case SyntaxKind::OpenBraceToken:
				return "{";
			case SyntaxKind::CloseBraceToken:
				return "}";
			case SyntaxKind::OpenBracketToken:
				return "[";
			case SyntaxKind::CloseBracketToken:
				return "]";

				// Unary operators
			case SyntaxKind::PlusPlusToken:
				return "++";
			case SyntaxKind::MinusMinusToken:
				return "--";
			case SyntaxKind::BangToken:
				return "!";
			case SyntaxKind::TildeToken:
				return "~";

				// Binary operators
			case SyntaxKind::PlusToken:
				return "+";
			case SyntaxKind::MinusToken:
				return "-";
			case SyntaxKind::AsteriskToken:
				return "*";
			case SyntaxKind::FSlashToken:
				return "/";
			case SyntaxKind::PercentToken:
				return "%";
			case SyntaxKind::CaretToken:
				return "^";

				// Conditional operators
			case SyntaxKind::BangEqualsToken:
				return "!=";
			case SyntaxKind::EqualsToken:
				return "=";
			case SyntaxKind::EqualsEqualsToken:
				return "==";
			case SyntaxKind::LessToken:
				return "<";
			case SyntaxKind::LessEqualsToken:
				return "<=";
			case SyntaxKind::GreaterToken:
				return ">";
			case SyntaxKind::GreaterEqualsToken:
				return ">=";
			case SyntaxKind::PipeToken:
				return "|";
			case SyntaxKind::PipePipeToken:
				return "||";
			case SyntaxKind::AmpersandToken:
				return "&";
			case SyntaxKind::AmpersandAmpersandToken:
				return "&&";
			case SyntaxKind::QuestionMarkToken:
				return "?";

				// Shifts
			case SyntaxKind::GreaterGreaterToken:
				return ">>";
			case SyntaxKind::LessLessToken:
				return "<<";

				// Compound assignment
			case SyntaxKind::PlusEqualsToken:
				return "+=";
			case SyntaxKind::MinusEqualsToken:
				return "-=";
			case SyntaxKind::AsteriskEqualsToken:
				return "*=";
			case SyntaxKind::FSlashEqualsToken:
				return "/=";
			case SyntaxKind::PercentEqualsToken:
				return "%=";
			case SyntaxKind::AmpersandEqualsToken:
				return "&=";
			case SyntaxKind::PipeEqualsToken:
				return "|=";
			case SyntaxKind::LessLessEqualsToken:
				return "<<=";
			case SyntaxKind::GreaterGreaterEqualsToken:
				return ">>=";
			case SyntaxKind::CaretEqualsToken:
				return "^=";
			case SyntaxKind::TildeEqualsToken:
				return "~=";

			// Compiler reserved keywords
			case SyntaxKind::TypeOfKeyword:
				return "typeof";
			case SyntaxKind::NameOfKeyword:
				return "nameof";
			case SyntaxKind::SizeOfKeyword:
				return "sizeof";
			case SyntaxKind::NewKeyword:
				return "new";
			case SyntaxKind::ClassKeyword:
				return "class";
			case SyntaxKind::StructKeyword:
				return "struct";

			case SyntaxKind::Int8Keyword:
				return "int8";
			case SyntaxKind::UInt8Keyword:
				return "uint8";
			case SyntaxKind::Int16Keyword:
				return "int16";
			case SyntaxKind::UInt16Keyword:
				return "uint16";
			case SyntaxKind::Int32Keyword:
				return "int32";
			case SyntaxKind::UInt32Keyword:
				return "uint32";
			case SyntaxKind::Int64Keyword:
				return "int64";
			case SyntaxKind::UInt64Keyword:
				return "uint64";

			case SyntaxKind::StringKeyword:
				return "string";
			case SyntaxKind::CharKeyword:
				return "char";
			case SyntaxKind::BoolKeyword:
				return "bool";

			case SyntaxKind::TrueKeyword:
				return "true";
			case SyntaxKind::FalseKeyword:
				return "false";

			case SyntaxKind::NilKeyword:
				return "nil";

			// If the switch reaches default, that means we either have an invalid token, or a keyword 
			default:
				return LookupMemberName(kind);
		}
	}

	// This should be self explanatory
	[[nodiscard]] static SyntaxKind LookupKeyword(const Types::Char8* input)
	{
		if (std::strcmp(input, "typeof") == 0)
		{
			return SyntaxKind::TypeOfKeyword;
		}
		if (std::strcmp(input, "nameof") == 0)
		{
			return SyntaxKind::NameOfKeyword;
		}
		if (std::strcmp(input, "sizeof") == 0)
		{
			return SyntaxKind::SizeOfKeyword;
		}
		if (std::strcmp(input, "new") == 0)
		{
			return SyntaxKind::NewKeyword;
		}


		if (std::strcmp(input, "int8") == 0)
		{
			return SyntaxKind::Int8Keyword;
		}
		if (std::strcmp(input, "uint8") == 0)
		{
			return SyntaxKind::UInt8Keyword;
		}
		if (std::strcmp(input, "int16") == 0)
		{
			return SyntaxKind::Int16Keyword;
		}
		if (std::strcmp(input, "uint16") == 0)
		{
			return SyntaxKind::UInt16Keyword;
		}
		if (std::strcmp(input, "int32") == 0)
		{
			return SyntaxKind::Int32Keyword;
		}
		if (std::strcmp(input, "uint32") == 0)
		{
			return SyntaxKind::UInt32Keyword;
		}
		if (std::strcmp(input, "int64") == 0)
		{
			return SyntaxKind::Int64Keyword;
		}
		if (std::strcmp(input, "uint64") == 0)
		{
			return SyntaxKind::UInt64Keyword;
		}
		if (std::strcmp(input, "float32") == 0)
		{
			return SyntaxKind::Float32Keyword;
		}
		if (std::strcmp(input, "float64") == 0)
		{
			return SyntaxKind::Float64Keyword;
		}



		if (std::strcmp(input, "string") == 0)
		{
			return SyntaxKind::StringKeyword;
		}
		if (std::strcmp(input, "char") == 0)
		{
			return SyntaxKind::CharKeyword;
		}
		if (std::strcmp(input, "bool") == 0)
		{
			return SyntaxKind::BoolKeyword;
		}
		if (std::strcmp(input, "true") == 0)
		{
			return SyntaxKind::TrueKeyword;
		}
		if (std::strcmp(input, "false") == 0)
		{
			return SyntaxKind::FalseKeyword;
		}

		if (std::strcmp(input, "nil") == 0)
		{
			return SyntaxKind::NilKeyword;
		}

		if (std::strcmp(input, "class") == 0)
		{
			return SyntaxKind::ClassKeyword;
		}
		if (std::strcmp(input, "struct") == 0)
		{
			return SyntaxKind::StructKeyword;
		}
		if (std::strcmp(input, "static") == 0)
		{
			return SyntaxKind::StaticKeyword;
		}

		return SyntaxKind::IdentifierToken;
	}
	
	// Since C++ doesn't have the ability to use reflection to get member data off enums such as their name
	// we map them to a dictionary to easily retrieve. This isn't used very often in the compiler itself,
	// but it's very nice to have this exposed as an outward facing API to access the names of a SyntaxKind (if ever needed)
	static std::unordered_map<SyntaxKind, const Types::Char8*> MemberNames
	{
		{SyntaxKind::BadToken, "BadToken"},
		{SyntaxKind::EndOfFileToken, "EndOfFileToken"},

		{SyntaxKind::WhiteSpaceToken, "WhiteSpaceToken"},
		{SyntaxKind::NewLineToken, "NewLineToken"},
		{SyntaxKind::SingleLineCommentToken, "SingleLineCommentToken"},
		{SyntaxKind::MultiLineToken, "MultiLineToken"},

		{SyntaxKind::OpenParenToken, "OpenParenToken"},
		{SyntaxKind::CloseParenToken, "CloseParenToken"},
		{SyntaxKind::OpenBraceToken, "OpenBraceToken"},
		{SyntaxKind::CloseBraceToken, "CloseBraceToken"},
		{SyntaxKind::OpenBracketToken, "OpenBracketToken"},
		{SyntaxKind::CloseBracketToken, "CloseBracketToken"},

		{SyntaxKind::TildeToken, "TildeToken"},
		{SyntaxKind::BangToken, "BangToken"},
		{SyntaxKind::PlusPlusToken, "PlusPlusToken"},
		{SyntaxKind::MinusMinusToken, "MinusMinusToken"},

		{SyntaxKind::PlusToken, "PlusToken"},
		{SyntaxKind::MinusToken, "MinusToken"},
		{SyntaxKind::AsteriskToken, "AsteriskToken"},
		{SyntaxKind::FSlashToken, "FSlashToken"},
		{SyntaxKind::PercentToken, "PercentToken"},
		{SyntaxKind::CaretToken, "CaretToken"},
		{SyntaxKind::QuestionMarkToken, "QuestionMarkToken"},

		{SyntaxKind::CaretEqualsToken, "CaretEqualsToken"},
		{SyntaxKind::PlusEqualsToken, "PlusEqualsToken"},
		{SyntaxKind::MinusEqualsToken, "MinusEqualsToken"},
		{SyntaxKind::AsteriskEqualsToken, "AsteriskEqualsToken"},
		{SyntaxKind::FSlashEqualsToken, "FSlashEqualsToken"},
		{SyntaxKind::PercentEqualsToken, "PercentEqualsToken"},
		{SyntaxKind::PipeEqualsToken, "PipeEqualsToken"},
		{SyntaxKind::AmpersandEqualsToken, "AmpersandEqualsToken"},
		{SyntaxKind::LessLessEqualsToken, "LessLessEqualsToken"},
		{SyntaxKind::GreaterGreaterEqualsToken, "GreaterGreaterEqualsToken"},
		{SyntaxKind::TildeEqualsToken, "TildeEqualsToken"},

		{SyntaxKind::BangEqualsToken, "BangEqualsToken"},
		{SyntaxKind::EqualsToken, "EqualsToken"},
		{SyntaxKind::EqualsEqualsToken, "EqualsEqualsToken"},
		{SyntaxKind::LessToken, "LessToken"},
		{SyntaxKind::LessEqualsToken, "LessEqualsToken"},
		{SyntaxKind::GreaterToken, "GreaterToken"},
		{SyntaxKind::GreaterEqualsToken, "GreaterEqualsToken"},
		{SyntaxKind::PipeToken, "PipeToken"},
		{SyntaxKind::PipePipeToken, "PipePipeToken"},
		{SyntaxKind::AmpersandToken, "AmpersandToken"},
		{SyntaxKind::AmpersandAmpersandToken, "AmpersandAmpersandToken"},

		{SyntaxKind::LessLessToken, "LessLessToken"},
		{SyntaxKind::GreaterGreaterToken, "GreaterGreaterToken"},

		{SyntaxKind::DotToken, "DotToken"},
		{SyntaxKind::CommaToken, "CommaToken"},
		{SyntaxKind::ColonToken, "ColonToken"},
		{SyntaxKind::SemicolonToken, "SemicolonToken"},

		{SyntaxKind::TypeOfKeyword, "TypeOfKeyword"},
		{SyntaxKind::NameOfKeyword, "NameOfKeyword"},
		{SyntaxKind::SizeOfKeyword, "SizeOfKeyword"},
		{SyntaxKind::NewKeyword, "NewKeyword"},

		{SyntaxKind::ClassKeyword, "ClassKeyword"},
		{SyntaxKind::StructKeyword, "StructKeyword"},
		{SyntaxKind::StaticKeyword, "StaticKeyword"},

		{SyntaxKind::NilKeyword, "NilKeyword"},

		{SyntaxKind::TrueKeyword, "TrueKeyword"},
		{SyntaxKind::FalseKeyword, "FalseKeyword"},

		{SyntaxKind::StringKeyword, "StringKeyword"},
		{SyntaxKind::CharKeyword, "CharKeyword"},
		{SyntaxKind::BoolKeyword, "BoolKeyword"},

		{SyntaxKind::Int8Keyword, "Int8Keyword"},
		{SyntaxKind::UInt8Keyword, "UInt8Keyword"},
		{SyntaxKind::Int16Keyword, "Int16Keyword"},
		{SyntaxKind::UInt16Keyword, "UInt16Keyword"},
		{SyntaxKind::Int32Keyword, "Int32Keyword"},
		{SyntaxKind::UInt32Keyword, "UInt32Keyword"},
		{SyntaxKind::Int64Keyword, "Int64Keyword"},
		{SyntaxKind::UInt64Keyword, "UInt64Keyword"},
		{SyntaxKind::Float32Keyword, "Float32Keyword"},
		{SyntaxKind::Float64Keyword, "Float64Keyword"},

		{SyntaxKind::IdentifierToken, "IdentifierToken"},
		{SyntaxKind::StringLiteralToken, "StringLiteralToken"},
		{SyntaxKind::CharLiteralToken, "CharLiteralToken"},

		{SyntaxKind::BoolLiteralToken, "BoolLiteralToken"},
		{SyntaxKind::Int8LiteralToken, "Int8LiteralToken"},
		{SyntaxKind::UInt8LiteralToken, "UInt8LiteralToken"},
		{SyntaxKind::Int16LiteralToken, "Int16LiteralToken"},
		{SyntaxKind::UInt16LiteralToken, "UInt16LiteralToken"},
		{SyntaxKind::Int32LiteralToken, "Int32LiteralToken"},
		{SyntaxKind::UInt32LiteralToken, "UInt32LiteralToken"},
		{SyntaxKind::Int64LiteralToken, "Int64LiteralToken"},
		{SyntaxKind::UInt64LiteralToken, "UInt64LiteralToken"},
		{SyntaxKind::Float32LiteralToken, "Float32LiteralToken"},
		{SyntaxKind::Float64LiteralToken, "Float64LiteralToken"},
	};

	// Attempt to locate locate a member from SyntaxKind, and return it's human readable name,
	// since we can retrieve via reflection, we have to use an unordered_map<TKey, TValue>
	[[nodiscard]] static const Types::Char8* LookupMemberName(const SyntaxKind kind)
	{
		if (MemberNames.find(kind) == MemberNames.end())
		{
			// this method should never be called in a serious environment, so returning
			// a "fake" token name will be a better indicator during debugging/testing.
			return "InvalidTokenKind";
		}

		return MemberNames[kind];
	}
}