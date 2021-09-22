#pragma once
#include <unordered_map>

#include "..\Utilities\Types.hpp"
#include "SyntaxKind.hpp"
#include "SyntaxData.hpp"

namespace VSharp::Syntax
{
	// This should be self explanatory
	[[nodiscard]] static SyntaxKind LookupKeyword(const std::wstring& input)
	{
		if (Keywords.find(input) == Keywords.end())
		{
			return SyntaxKind::IdentifierToken;
		}

		return Keywords.at(input);
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

		return MemberNames.at(kind);
	}
}