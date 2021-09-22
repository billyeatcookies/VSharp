#pragma once
#include <unordered_map>

#include "..\Utilities\Types.hpp"
#include "SyntaxKind.hpp"
#include "SyntaxData.hpp"

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
		// I've been having issues getting (Keywords.find(input == Keywords.end()) for looking up
		// keys in the map to work, and I'm not sure why it refuses to work reliably, so I'm just
		// going to manually loop until someone finds a fix :/
		// HOWEVER, LookupMemberName seems to work perfectly fine for this method, and I don't know why.

		// Possible reasons for lookup failing (at least what I thought of):
		// 1. mismatch length
		// 2. invisible whitespace
		// 3. encoding issues
		// but none of these SHOULD be the cause, since I've attempted printing out these values
		for (const auto& [text, kind] : Keywords)
		{
			if (strcmp(text, input) == 0)
			{
				return kind;
			}
		}

		return SyntaxKind::IdentifierToken;
	}
	
	
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