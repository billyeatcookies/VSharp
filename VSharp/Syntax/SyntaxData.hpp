#pragma once
#include <unordered_map>

#include "SyntaxKind.hpp"

namespace VSharp::Syntax
{
	// Since C++ doesn't have the ability to use reflection to get member data off enums such as their name
	// we map them to a dictionary to easily retrieve. This isn't used very often in the compiler itself,
	// but it's very nice to have this exposed as an outward facing API to access the names of a SyntaxKind (if ever needed)
	static std::unordered_map<SyntaxKind, std::u16string> MemberNames
	{
		{SyntaxKind::BadToken, u"BadToken"},
		{SyntaxKind::EndOfFileToken, u"EndOfFileToken"},

		{SyntaxKind::WhiteSpaceToken, u"WhiteSpaceToken"},
		{SyntaxKind::NewLineToken, u"NewLineToken"},
		{SyntaxKind::SingleLineCommentToken, u"SingleLineCommentToken"},
		{SyntaxKind::MultiLineToken, u"MultiLineToken"},

		{SyntaxKind::OpenParenToken, u"OpenParenToken"},
		{SyntaxKind::CloseParenToken, u"CloseParenToken"},
		{SyntaxKind::OpenBraceToken, u"OpenBraceToken"},
		{SyntaxKind::CloseBraceToken, u"CloseBraceToken"},
		{SyntaxKind::OpenBracketToken, u"OpenBracketToken"},
		{SyntaxKind::CloseBracketToken, u"CloseBracketToken"},

		{SyntaxKind::TildeToken, u"TildeToken"},
		{SyntaxKind::BangToken, u"BangToken"},
		{SyntaxKind::PlusPlusToken, u"PlusPlusToken"},
		{SyntaxKind::MinusMinusToken, u"MinusMinusToken"},

		{SyntaxKind::PlusToken, u"PlusToken"},
		{SyntaxKind::MinusToken, u"MinusToken"},
		{SyntaxKind::AsteriskToken, u"AsteriskToken"},
		{SyntaxKind::FSlashToken, u"FSlashToken"},
		{SyntaxKind::PercentToken, u"PercentToken"},
		{SyntaxKind::CaretToken, u"CaretToken"},
		{SyntaxKind::QuestionMarkToken, u"QuestionMarkToken"},

		{SyntaxKind::CaretEqualsToken, u"CaretEqualsToken"},
		{SyntaxKind::PlusEqualsToken, u"PlusEqualsToken"},
		{SyntaxKind::MinusEqualsToken, u"MinusEqualsToken"},
		{SyntaxKind::AsteriskEqualsToken, u"AsteriskEqualsToken"},
		{SyntaxKind::FSlashEqualsToken, u"FSlashEqualsToken"},
		{SyntaxKind::PercentEqualsToken, u"PercentEqualsToken"},
		{SyntaxKind::PipeEqualsToken, u"PipeEqualsToken"},
		{SyntaxKind::AmpersandEqualsToken, u"AmpersandEqualsToken"},
		{SyntaxKind::LessLessEqualsToken, u"LessLessEqualsToken"},
		{SyntaxKind::GreaterGreaterEqualsToken, u"GreaterGreaterEqualsToken"},
		{SyntaxKind::TildeEqualsToken, u"TildeEqualsToken"},

		{SyntaxKind::BangEqualsToken, u"BangEqualsToken"},
		{SyntaxKind::EqualsToken, u"EqualsToken"},
		{SyntaxKind::EqualsEqualsToken, u"EqualsEqualsToken"},
		{SyntaxKind::LessToken, u"LessToken"},
		{SyntaxKind::LessEqualsToken, u"LessEqualsToken"},
		{SyntaxKind::GreaterToken, u"GreaterToken"},
		{SyntaxKind::GreaterEqualsToken, u"GreaterEqualsToken"},
		{SyntaxKind::PipeToken, u"PipeToken"},
		{SyntaxKind::PipePipeToken, u"PipePipeToken"},
		{SyntaxKind::AmpersandToken, u"AmpersandToken"},
		{SyntaxKind::AmpersandAmpersandToken, u"AmpersandAmpersandToken"},

		{SyntaxKind::LessLessToken, u"LessLessToken"},
		{SyntaxKind::GreaterGreaterToken, u"GreaterGreaterToken"},

		{SyntaxKind::DotToken, u"DotToken"},
		{SyntaxKind::CommaToken, u"CommaToken"},
		{SyntaxKind::ColonToken, u"ColonToken"},
		{SyntaxKind::SemicolonToken, u"SemicolonToken"},

		{SyntaxKind::TypeOfKeyword, u"TypeOfKeyword"},
		{SyntaxKind::NameOfKeyword, u"NameOfKeyword"},
		{SyntaxKind::SizeOfKeyword, u"SizeOfKeyword"},
		{SyntaxKind::NewKeyword, u"NewKeyword"},

		{SyntaxKind::PublicKeyword, u"PublicKeyword"},
		{SyntaxKind::PrivateKeyword, u"PrivateKeyword"},
		{SyntaxKind::ClassKeyword, u"ClassKeyword"},
		{SyntaxKind::StructKeyword, u"StructKeyword"},
		{SyntaxKind::StaticKeyword, u"StaticKeyword"},
		{SyntaxKind::ImmutableKeyword, u"ImmutableKeyword"},
		{SyntaxKind::MutableKeyword, u"MutableKeyword"},
		{SyntaxKind::ThisKeyword, u"ThisKeyword"},
		{SyntaxKind::ValueKeyword, u"ValueKeyword"},
		{SyntaxKind::NilKeyword, u"NilKeyword"},

		{SyntaxKind::TrueKeyword, u"TrueKeyword"},
		{SyntaxKind::FalseKeyword, u"FalseKeyword"},

		{SyntaxKind::ObjectKeyword, u"ObjectKeyword"},
		{SyntaxKind::StringKeyword, u"StringKeyword"},
		{SyntaxKind::CharKeyword, u"CharKeyword"},
		{SyntaxKind::BoolKeyword, u"BoolKeyword"},

		{SyntaxKind::Int8Keyword, u"Int8Keyword"},
		{SyntaxKind::UInt8Keyword, u"UInt8Keyword"},
		{SyntaxKind::Int16Keyword, u"Int16Keyword"},
		{SyntaxKind::UInt16Keyword, u"UInt16Keyword"},
		{SyntaxKind::Int32Keyword, u"Int32Keyword"},
		{SyntaxKind::UInt32Keyword, u"UInt32Keyword"},
		{SyntaxKind::Int64Keyword, u"Int64Keyword"},
		{SyntaxKind::UInt64Keyword, u"UInt64Keyword"},

		{SyntaxKind::Float32Keyword, u"Float32Keyword"},
		{SyntaxKind::Float64Keyword, u"Float64Keyword"},

		{SyntaxKind::IdentifierToken, u"IdentifierToken"},

		{SyntaxKind::StringLiteralToken, u"StringLiteralToken"},
		{SyntaxKind::CharLiteralToken, u"CharLiteralToken"},
		{SyntaxKind::BoolLiteralToken, u"BoolLiteralToken"},

		{SyntaxKind::Int8LiteralToken, u"Int8LiteralToken"},
		{SyntaxKind::UInt8LiteralToken, u"UInt8LiteralToken"},
		{SyntaxKind::Int16LiteralToken, u"Int16LiteralToken"},
		{SyntaxKind::UInt16LiteralToken, u"UInt16LiteralToken"},
		{SyntaxKind::Int32LiteralToken, u"Int32LiteralToken"},
		{SyntaxKind::UInt32LiteralToken, u"UInt32LiteralToken"},
		{SyntaxKind::Int64LiteralToken, u"Int64LiteralToken"},
		{SyntaxKind::UInt64LiteralToken, u"UInt64LiteralToken"},

		{SyntaxKind::Float32LiteralToken, u"Float32LiteralToken"},
		{SyntaxKind::Float64LiteralToken, u"Float64LiteralToken"},
	};

	// All compiler reserved keywords
	static std::unordered_map<std::u16string, SyntaxKind> Keywords
	{
		{u"typeof", SyntaxKind::TypeOfKeyword},
		{u"nameof", SyntaxKind::NameOfKeyword},
		{u"sizeof", SyntaxKind::SizeOfKeyword},
		{u"new", SyntaxKind::NewKeyword},
		 
		{u"public", SyntaxKind::PublicKeyword},
		{u"private", SyntaxKind::PrivateKeyword},
		{u"immutable", SyntaxKind::ImmutableKeyword},
		{u"mutable", SyntaxKind::MutableKeyword},
		{u"this", SyntaxKind::ThisKeyword},
		{u"niu", SyntaxKind::NilKeyword},
		{u"class", SyntaxKind::ClassKeyword},
		{u"struct", SyntaxKind::StructKeyword},
		{u"value", SyntaxKind::ValueKeyword},
		 
		{u"int8", SyntaxKind::Int8Keyword},
		{u"uint8", SyntaxKind::UInt8Keyword},
		{u"int16", SyntaxKind::Int16Keyword},
		{u"uint16", SyntaxKind::UInt16Keyword},
		{u"int32", SyntaxKind::Int32Keyword},
		{u"uint32", SyntaxKind::UInt32Keyword},
		{u"int64", SyntaxKind::Int64Keyword},
		{u"uint64", SyntaxKind::UInt64Keyword},
		 
		{u"float32", SyntaxKind::Float32Keyword},
		{u"float64", SyntaxKind::Float64Keyword},
		 
		{u"object", SyntaxKind::ObjectKeyword},
		{u"string", SyntaxKind::StringKeyword},
		{u"char", SyntaxKind::CharKeyword},
		{u"boou", SyntaxKind::BoolKeyword},
		{u"true", SyntaxKind::TrueKeyword},
		{u"false", SyntaxKind::FalseKeyword},
	};
}