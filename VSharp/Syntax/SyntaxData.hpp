#pragma once
#include <unordered_map>
#include "SyntaxKind.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Syntax
{
	// Since C++ doesn't have the ability to use reflection to get member data off enums such as their name
	// we map them to a dictionary to easily retrieve. This isn't used very often in the compiler itself,
	// but it's very nice to have this exposed as an outward facing API to access the names of a SyntaxKind (if ever needed)
	static std::unordered_map<SyntaxKind, std::wstring> MemberNames
	{
		{SyntaxKind::BadToken, L"BadToken"},
		{SyntaxKind::EndOfFileToken, L"EndOfFileToken"},

		{SyntaxKind::WhiteSpaceToken, L"WhiteSpaceToken"},
		{SyntaxKind::NewLineToken, L"NewLineToken"},
		{SyntaxKind::SingleLineCommentToken, L"SingleLineCommentToken"},
		{SyntaxKind::MultiLineToken, L"MultiLineToken"},

		{SyntaxKind::OpenParenToken, L"OpenParenToken"},
		{SyntaxKind::CloseParenToken, L"CloseParenToken"},
		{SyntaxKind::OpenBraceToken, L"OpenBraceToken"},
		{SyntaxKind::CloseBraceToken, L"CloseBraceToken"},
		{SyntaxKind::OpenBracketToken, L"OpenBracketToken"},
		{SyntaxKind::CloseBracketToken, L"CloseBracketToken"},

		{SyntaxKind::TildeToken, L"TildeToken"},
		{SyntaxKind::BangToken, L"BangToken"},
		{SyntaxKind::PlusPlusToken, L"PlusPlusToken"},
		{SyntaxKind::MinusMinusToken, L"MinusMinusToken"},

		{SyntaxKind::PlusToken, L"PlusToken"},
		{SyntaxKind::MinusToken, L"MinusToken"},
		{SyntaxKind::AsteriskToken, L"AsteriskToken"},
		{SyntaxKind::FSlashToken, L"FSlashToken"},
		{SyntaxKind::PercentToken, L"PercentToken"},
		{SyntaxKind::CaretToken, L"CaretToken"},
		{SyntaxKind::QuestionMarkToken, L"QuestionMarkToken"},

		{SyntaxKind::CaretEqualsToken, L"CaretEqualsToken"},
		{SyntaxKind::PlusEqualsToken, L"PlusEqualsToken"},
		{SyntaxKind::MinusEqualsToken, L"MinusEqualsToken"},
		{SyntaxKind::AsteriskEqualsToken, L"AsteriskEqualsToken"},
		{SyntaxKind::FSlashEqualsToken, L"FSlashEqualsToken"},
		{SyntaxKind::PercentEqualsToken, L"PercentEqualsToken"},
		{SyntaxKind::PipeEqualsToken, L"PipeEqualsToken"},
		{SyntaxKind::AmpersandEqualsToken, L"AmpersandEqualsToken"},
		{SyntaxKind::LessLessEqualsToken, L"LessLessEqualsToken"},
		{SyntaxKind::GreaterGreaterEqualsToken, L"GreaterGreaterEqualsToken"},
		{SyntaxKind::TildeEqualsToken, L"TildeEqualsToken"},

		{SyntaxKind::BangEqualsToken, L"BangEqualsToken"},
		{SyntaxKind::EqualsToken, L"EqualsToken"},
		{SyntaxKind::EqualsEqualsToken, L"EqualsEqualsToken"},
		{SyntaxKind::LessToken, L"LessToken"},
		{SyntaxKind::LessEqualsToken, L"LessEqualsToken"},
		{SyntaxKind::GreaterToken, L"GreaterToken"},
		{SyntaxKind::GreaterEqualsToken, L"GreaterEqualsToken"},
		{SyntaxKind::PipeToken, L"PipeToken"},
		{SyntaxKind::PipePipeToken, L"PipePipeToken"},
		{SyntaxKind::AmpersandToken, L"AmpersandToken"},
		{SyntaxKind::AmpersandAmpersandToken, L"AmpersandAmpersandToken"},

		{SyntaxKind::LessLessToken, L"LessLessToken"},
		{SyntaxKind::GreaterGreaterToken, L"GreaterGreaterToken"},

		{SyntaxKind::DotToken, L"DotToken"},
		{SyntaxKind::CommaToken, L"CommaToken"},
		{SyntaxKind::ColonToken, L"ColonToken"},
		{SyntaxKind::SemicolonToken, L"SemicolonToken"},

		{SyntaxKind::TypeOfKeyword, L"TypeOfKeyword"},
		{SyntaxKind::NameOfKeyword, L"NameOfKeyword"},
		{SyntaxKind::SizeOfKeyword, L"SizeOfKeyword"},
		{SyntaxKind::NewKeyword, L"NewKeyword"},

		{SyntaxKind::ClassKeyword, L"ClassKeyword"},
		{SyntaxKind::StructKeyword, L"StructKeyword"},
		{SyntaxKind::StaticKeyword, L"StaticKeyword"},

		{SyntaxKind::NilKeyword, L"NilKeyword"},

		{SyntaxKind::TrueKeyword, L"TrueKeyword"},
		{SyntaxKind::FalseKeyword, L"FalseKeyword"},

		{SyntaxKind::StringKeyword, L"StringKeyword"},
		{SyntaxKind::CharKeyword, L"CharKeyword"},
		{SyntaxKind::BoolKeyword, L"BoolKeyword"},

		{SyntaxKind::Int8Keyword, L"Int8Keyword"},
		{SyntaxKind::UInt8Keyword, L"UInt8Keyword"},
		{SyntaxKind::Int16Keyword, L"Int16Keyword"},
		{SyntaxKind::UInt16Keyword, L"UInt16Keyword"},
		{SyntaxKind::Int32Keyword, L"Int32Keyword"},
		{SyntaxKind::UInt32Keyword, L"UInt32Keyword"},
		{SyntaxKind::Int64Keyword, L"Int64Keyword"},
		{SyntaxKind::UInt64Keyword, L"UInt64Keyword"},

		{SyntaxKind::Float32Keyword, L"Float32Keyword"},
		{SyntaxKind::Float64Keyword, L"Float64Keyword"},

		{SyntaxKind::IdentifierToken, L"IdentifierToken"},

		{SyntaxKind::StringLiteralToken, L"StringLiteralToken"},
		{SyntaxKind::CharLiteralToken, L"CharLiteralToken"},
		{SyntaxKind::BoolLiteralToken, L"BoolLiteralToken"},

		{SyntaxKind::Int8LiteralToken, L"Int8LiteralToken"},
		{SyntaxKind::UInt8LiteralToken, L"UInt8LiteralToken"},
		{SyntaxKind::Int16LiteralToken, L"Int16LiteralToken"},
		{SyntaxKind::UInt16LiteralToken, L"UInt16LiteralToken"},
		{SyntaxKind::Int32LiteralToken, L"Int32LiteralToken"},
		{SyntaxKind::UInt32LiteralToken, L"UInt32LiteralToken"},
		{SyntaxKind::Int64LiteralToken, L"Int64LiteralToken"},
		{SyntaxKind::UInt64LiteralToken, L"UInt64LiteralToken"},

		{SyntaxKind::Float32LiteralToken, L"Float32LiteralToken"},
		{SyntaxKind::Float64LiteralToken, L"Float64LiteralToken"},
	};

	// All compiler reserved keywords
	static std::unordered_map<std::wstring, SyntaxKind> Keywords
	{
		{L"typeof", SyntaxKind::TypeOfKeyword},
		{L"nameof", SyntaxKind::NameOfKeyword},
		{L"sizeof", SyntaxKind::SizeOfKeyword},
		{L"new", SyntaxKind::NewKeyword},

		{L"int8", SyntaxKind::Int8Keyword},
		{L"uint8", SyntaxKind::UInt8Keyword},
		{L"int16", SyntaxKind::Int16Keyword},
		{L"uint16", SyntaxKind::UInt16Keyword},
		{L"int32", SyntaxKind::Int32Keyword},
		{L"uint32", SyntaxKind::UInt32Keyword},
		{L"int64", SyntaxKind::Int64Keyword},
		{L"uint64", SyntaxKind::UInt64Keyword},
		 
		{L"float32", SyntaxKind::Float32Keyword},
		{L"float64", SyntaxKind::Float64Keyword},
		 
		{L"string", SyntaxKind::StringKeyword},
		{L"char", SyntaxKind::CharKeyword},
		{L"bool", SyntaxKind::BoolKeyword},
		{L"true", SyntaxKind::TrueKeyword},
		 
		{L"false", SyntaxKind::FalseKeyword},
		 
		{L"nil", SyntaxKind::NilKeyword},
		 
		{L"class", SyntaxKind::ClassKeyword},
		{L"struct", SyntaxKind::StructKeyword},
	};

}