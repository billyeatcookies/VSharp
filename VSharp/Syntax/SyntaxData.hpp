#pragma once
#include <unordered_map>
#include "SyntaxKind.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Syntax
{
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

	// All compiler reserved keywords
	static std::unordered_map<const char*, SyntaxKind> Keywords
	{
		{"typeof", SyntaxKind::TypeOfKeyword},
		{"nameof", SyntaxKind::NameOfKeyword},
		{"sizeof", SyntaxKind::SizeOfKeyword},
		{"new", SyntaxKind::NewKeyword},

		{"int8", SyntaxKind::Int8Keyword},
		{"uint8", SyntaxKind::UInt8Keyword},
		{"int16", SyntaxKind::Int16Keyword},
		{"uint16", SyntaxKind::UInt16Keyword},
		{"int32", SyntaxKind::Int32Keyword},
		{"uint32", SyntaxKind::UInt32Keyword},
		{"int64", SyntaxKind::Int64Keyword},
		{"uint64", SyntaxKind::UInt64Keyword},

		{"float32", SyntaxKind::Float32Keyword},
		{"float64", SyntaxKind::Float64Keyword},

		{"string", SyntaxKind::StringKeyword},
		{"char", SyntaxKind::CharKeyword},
		{"bool", SyntaxKind::BoolKeyword},
		{"true", SyntaxKind::TrueKeyword},

		{"false", SyntaxKind::FalseKeyword},

		{"nil", SyntaxKind::NilKeyword},

		{"class", SyntaxKind::ClassKeyword},
		{"struct", SyntaxKind::StructKeyword},
	};

}