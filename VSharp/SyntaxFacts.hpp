#pragma once
#include <unordered_map>

#include "Types.hpp"

namespace VSharp
{
	enum class SyntaxKind
	{
		BadToken,
		EndOfFileToken,
		WhiteSpaceToken,
		NewLineToken,
		SingleLineCommentToken,
		MultiLineToken,

		OpenParenToken,
		CloseParenToken,
		OpenBraceToken,
		CloseBraceToken,
		OpenBracketToken,
		CloseBracketToken,

		// Unary
		// these are also unary in single + or - form
		BangToken,
		PlusPlusToken,
		MinusMinusToken,

		// Binary operators
		PlusToken,
		MinusToken,
		AsteriskToken,
		FSlashToken,
		PercentToken,
		QuestionMarkToken,

		// Compound assignment
		PlusEqualsToken,
		MinusEqualsToken,
		AsteriskEqualsToken,
		FSlashEqualsToken,
		PercentEqualsToken,
		PipeEqualsToken,
		AmpersandEqualsToken,

		BangEqualsToken,
		EqualsToken,
		EqualsEqualsToken,
		LessToken,
		LessEqualsToken,
		GreaterToken,
		GreaterEqualsToken,
		PipeToken,
		PipePipeToken,
		AmpersandToken,
		AmpersandAmpersandToken,

		// Shifts
		LessLessToken,
		GreaterGreaterToken,

		// Delimiters
		DotToken,
		CommaToken,
		ColonToken,
		SemicolonToken,

		// Type keywords
		NilKeyword,
		TrueKeyword,
		FalseKeyword,
		StringKeyword,
		CharKeyword,
		BoolKeyword,
		Int8Keyword,
		UInt8Keyword,
		Int16Keyword,
		UInt16Keyword,
		Int32Keyword,
		UInt32Keyword,
		Int64Keyword,
		UInt64Keyword,
		Float32Keyword,
		Float64Keyword,

		IdentifierToken,

		// Literal values
		// Lexing is the only time we have the easiest access to the literals true type,
		// assigning it to a true literal token will allow us to any_cast<T> the type to
		// the proper .NET type for binding/compilation. Switching enums is also cheaper
		// than type validation :)
		StringLiteralToken,
		CharLiteralToken,
		BoolLiteralToken,
		Int8LiteralToken,
		UInt8LiteralToken,
		Int16LiteralToken,
		UInt16LiteralToken,
		Int32LiteralToken,
		UInt32LiteralToken,
		Int64LiteralToken,
		UInt64LiteralToken,
		Float32LiteralToken,
		Float64LiteralToken,
	};

	[[nodiscard]] static const char* GetText(const SyntaxKind kind)
	{
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

			case SyntaxKind::BadToken: 
				return "BadToken";
			case SyntaxKind::EndOfFileToken: 
				return "EndOfFileToken";
			case SyntaxKind::WhiteSpaceToken: 
				return "WhiteSpaceToken";
			case SyntaxKind::NewLineToken: 
				return "NewLineToken";
			case SyntaxKind::SingleLineCommentToken: 
				return "SingleLineCommentToken";
			case SyntaxKind::MultiLineToken: 
				return "MultiLineToken";
			case SyntaxKind::IdentifierToken: 
				return "IdentifierToken";
			case SyntaxKind::NumericLiteralToken: 
				return "NumericLiteralToken";
			case SyntaxKind::StringLiteralToken: 
				return "StringLiteralToken";
			case SyntaxKind::CharLiteralToken: 
				return "CharLiteralToken";
		}

	}
	
	static std::unordered_map<SyntaxKind, const char*> MemberNames
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

		{SyntaxKind::BangToken, "BangToken"},
		{SyntaxKind::PlusPlusToken, "PlusPlusToken"},
		{SyntaxKind::MinusMinusToken, "MinusMinusToken"},

		{SyntaxKind::PlusToken, "PlusToken"},
		{SyntaxKind::MinusToken, "MinusToken"},
		{SyntaxKind::AsteriskToken, "AsteriskToken"},
		{SyntaxKind::FSlashToken, "FSlashToken"},
		{SyntaxKind::PercentToken, "PercentToken"},
		{SyntaxKind::QuestionMarkToken, "QuestionMarkToken"},

		{SyntaxKind::PlusEqualsToken, "PlusEqualsToken"},
		{SyntaxKind::MinusEqualsToken, "MinusEqualsToken"},
		{SyntaxKind::AsteriskEqualsToken, "AsteriskEqualsToken"},
		{SyntaxKind::FSlashEqualsToken, "FSlashEqualsToken"},
		{SyntaxKind::PercentEqualsToken, "PercentEqualsToken"},
		{SyntaxKind::PipeEqualsToken, "PipeEqualsToken"},
		{SyntaxKind::AmpersandEqualsToken, "AmpersandEqualsToken"},

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

		{SyntaxKind::IdentifierToken, "IdentifierToken"},
		{SyntaxKind::NumericLiteralToken, "NumericLiteralToken"},
		{SyntaxKind::StringLiteralToken, "StringLiteralToken"},
		{SyntaxKind::CharLiteralToken, "CharLiteralToken"},
	};

	static const Char8* LookupMemberName(const SyntaxKind kind)
	{
		if (MemberNames.find(kind) == MemberNames.end())
		{
			return "InvalidTokenKind";
		}

		return MemberNames[kind];
	}

	static std::unordered_map<const char*, SyntaxKind> Keywords
	{
		{"int8", SyntaxKind::Int8Keyword},
		{"uint8", SyntaxKind::UInt8Keyword},
		{"int16", SyntaxKind::Int16Keyword},
		{"uint16", SyntaxKind::UInt16Keyword},
		{"int32", SyntaxKind::Int32Keyword},
		{"uint32", SyntaxKind::UInt32Keyword},
		{"int64", SyntaxKind::Int64Keyword},
		{"uint64", SyntaxKind::UInt64Keyword},
		{"string", SyntaxKind::StringKeyword},
		{"char", SyntaxKind::CharKeyword},
		{"bool", SyntaxKind::BoolKeyword},
		{"true", SyntaxKind::TrueKeyword},
		{"false", SyntaxKind::FalseKeyword},
		{"nil", SyntaxKind::NilKeyword},
	};

	[[nodiscard]] static SyntaxKind LookupKeyword(const char* input)
	{
		if (Keywords.find(input) == Keywords.end())
		{
			return SyntaxKind::IdentifierToken;
		}

		return Keywords[input];
	}
}