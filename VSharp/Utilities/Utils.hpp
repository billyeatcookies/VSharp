#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include "Types.hpp"
#include <tuple>

namespace VSharp::Utilities
{
	[[nodiscard]] static const Types::Char8* Substring(const Types::Char8* input, const Types::UInt64 start, const Types::UInt64 length)
	{
		Types::Char8* buffer = new Types::Char8[static_cast<Types::UInt32>(length + 1ui64)];
		for (Types::UInt64 i = 0; i < length; i++)
		{
			buffer[i] = *(input + start + i);
		}

		buffer[length] = 0;
		return buffer;
	}

	[[nodiscard]] static const Types::Char8* ToCharPtr(const std::string& input)
	{
		return Substring(input.c_str(), 0, input.length());
	}
	
	[[nodiscard]] static bool FileExists(const Types::Char8* filepath)
	{
		return std::filesystem::exists(filepath);
	}

	[[nodiscard]] static const Types::Char8* LoadFile(const Types::Char8* filepath)
	{
		if (!FileExists(filepath))
		{
			std::cerr << "error: unable to locate file: " << filepath << std::endl;
			return "";
		}

		std::ifstream bufferStream(filepath);
		const std::string text = std::string(std::istreambuf_iterator<Types::Char8>(bufferStream), std::istreambuf_iterator<Types::Char8>());
		return ToCharPtr(text);
	}

	[[nodiscard]] static bool IsWhiteSpace(const Types::Char8& ch)
	{
		return isspace(ch);
	}

	// TODO: Support more unicode? What happens if someone writes code in Russian or Chinese?
	[[nodiscard]] static bool IsAlpha(const Types::Char8& ch)
	{
		return ch >= 'a' && ch <= 'z' ||
			   ch >= 'A' && ch <= 'Z' || ch == '_';
	}

	// My own IsDigit that just checks the character directly because I don't like built in
	[[nodiscard]] static bool IsDigit(const Types::Char8& ch)
	{
		return ch >= '0' && ch <= '9';
	}

	// Used for identifying keywords and identifiers, since identifiers can contain numbers and underscores
	// NOTICE: don't use this until you've used IsAlpha(ch) to ENSURE that the first character is an underscore
	// or valid ASCII character.
	[[nodiscard]] static bool IsAlphanumeric(const Types::Char8& ch)
	{
		return IsAlpha(ch) || IsDigit(ch);
	}
}
