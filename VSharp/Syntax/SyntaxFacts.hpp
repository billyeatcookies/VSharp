#pragma once
#include <unordered_map>

#include "..\Utilities\Types.hpp"
#include "SyntaxKind.hpp"
#include "SyntaxData.hpp"

namespace VSharp::Syntax
{
	[[nodiscard]] static std::wstring LookupMemberName(const SyntaxKind kind);
	[[nodiscard]] static SyntaxKind LookupKeyword(const std::wstring& input);

	[[nodiscard]] static std::wstring GetText(const SyntaxKind kind)
	{
		// TODO: I'm not sure if I want this to also be an unordered_map yet since it's also sharing reserved keywords 
		
		// DO NOT handle a token that doesn't represent a set of text on it's own,
		// ex: IdentifierToken, BadToken, Float32Literal -- these tokens are used to
		// compliment the fully constructed token and provide extra info. By keeping cases
		// as short as possible we can keep this file size as small as possible... hopefully
		switch (kind)
		{
			case SyntaxKind::ColonToken:
				return L":";
			case SyntaxKind::SemicolonToken:
				return L";";
			case SyntaxKind::DotToken:
				return L".";
			case SyntaxKind::CommaToken:
				return L",";
			case SyntaxKind::OpenParenToken:
				return L"(";
			case SyntaxKind::CloseParenToken:
				return L")";
			case SyntaxKind::OpenBraceToken:
				return L"{";
			case SyntaxKind::CloseBraceToken:
				return L"}";
			case SyntaxKind::OpenBracketToken:
				return L"[";
			case SyntaxKind::CloseBracketToken:
				return L"]";

				// Unary operators
			case SyntaxKind::PlusPlusToken:
				return L"++";
			case SyntaxKind::MinusMinusToken:
				return L"--";
			case SyntaxKind::BangToken:
				return L"!";
			case SyntaxKind::TildeToken:
				return L"~";

				// Binary operators
			case SyntaxKind::PlusToken:
				return L"+";
			case SyntaxKind::MinusToken:
				return L"-";
			case SyntaxKind::AsteriskToken:
				return L"*";
			case SyntaxKind::FSlashToken:
				return L"/";
			case SyntaxKind::PercentToken:
				return L"%";
			case SyntaxKind::CaretToken:
				return L"^";

				// Conditional operators
			case SyntaxKind::BangEqualsToken:
				return L"!=";
			case SyntaxKind::EqualsToken:
				return L"=";
			case SyntaxKind::EqualsEqualsToken:
				return L"==";
			case SyntaxKind::LessToken:
				return L"<";
			case SyntaxKind::LessEqualsToken:
				return L"<=";
			case SyntaxKind::GreaterToken:
				return L">";
			case SyntaxKind::GreaterEqualsToken:
				return L">=";
			case SyntaxKind::PipeToken:
				return L"|";
			case SyntaxKind::PipePipeToken:
				return L"||";
			case SyntaxKind::AmpersandToken:
				return L"&";
			case SyntaxKind::AmpersandAmpersandToken:
				return L"&&";
			case SyntaxKind::QuestionMarkToken:
				return L"?";

				// Shifts
			case SyntaxKind::GreaterGreaterToken:
				return L">>";
			case SyntaxKind::LessLessToken:
				return L"<<";

				// Compound assignment
			case SyntaxKind::PlusEqualsToken:
				return L"+=";
			case SyntaxKind::MinusEqualsToken:
				return L"-=";
			case SyntaxKind::AsteriskEqualsToken:
				return L"*=";
			case SyntaxKind::FSlashEqualsToken:
				return L"/=";
			case SyntaxKind::PercentEqualsToken:
				return L"%=";
			case SyntaxKind::AmpersandEqualsToken:
				return L"&=";
			case SyntaxKind::PipeEqualsToken:
				return L"|=";
			case SyntaxKind::LessLessEqualsToken:
				return L"<<=";
			case SyntaxKind::GreaterGreaterEqualsToken:
				return L">>=";
			case SyntaxKind::CaretEqualsToken:
				return L"^=";
			case SyntaxKind::TildeEqualsToken:
				return L"~=";

			// Compiler reserved keywords
			case SyntaxKind::TypeOfKeyword:
				return L"typeof";
			case SyntaxKind::NameOfKeyword:
				return L"nameof";
			case SyntaxKind::SizeOfKeyword:
				return L"sizeof";
			case SyntaxKind::NewKeyword:
				return L"new";
			case SyntaxKind::ClassKeyword:
				return L"class";
			case SyntaxKind::StructKeyword:
				return L"struct";

			case SyntaxKind::Int8Keyword:
				return L"int8";
			case SyntaxKind::UInt8Keyword:
				return L"uint8";
			case SyntaxKind::Int16Keyword:
				return L"int16";
			case SyntaxKind::UInt16Keyword:
				return L"uint16";
			case SyntaxKind::Int32Keyword:
				return L"int32";
			case SyntaxKind::UInt32Keyword:
				return L"uint32";
			case SyntaxKind::Int64Keyword:
				return L"int64";
			case SyntaxKind::UInt64Keyword:
				return L"uint64";

			case SyntaxKind::StringKeyword:
				return L"string";
			case SyntaxKind::CharKeyword:
				return L"char";
			case SyntaxKind::BoolKeyword:
				return L"bool";
			case SyntaxKind::TrueKeyword:
				return L"true";
			case SyntaxKind::FalseKeyword:
				return L"false";

			case SyntaxKind::NilKeyword:
				return L"nil";

			// If the switch reaches default, that means we either have an invalid token, or a keyword 
			default:
				return LookupMemberName(kind);
		}
	}

	// This should be self explanatory
	[[nodiscard]] static SyntaxKind LookupKeyword(const std::wstring& input)
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
			if (text == input)
			{
				return kind;
			}
		}

		return SyntaxKind::IdentifierToken;
	}

	// Attempt to locate locate a member from SyntaxKind, and return it's human readable name,
	// since we can retrieve via reflection, we have to use an unordered_map<TKey, TValue>
	[[nodiscard]] static std::wstring LookupMemberName(const SyntaxKind kind)
	{
		if (MemberNames.find(kind) == MemberNames.end())
		{
			// this method should never be called in a serious environment, so returning
			// a "fake" token name will be a better indicator during debugging/testing.
			return L"InvalidTokenKind";
		}

		return MemberNames[kind];
	}
}