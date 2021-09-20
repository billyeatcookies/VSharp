#pragma once
#include <filesystem>
#include <fstream>

namespace VSharp
{
	[[nodiscard]] static bool FileExists(const Char8* filepath)
	{
		return std::filesystem::exists(filepath);
	}

	[[nodiscard]] static const Char8* Substring(const Char8* arr, const UInt64 start, const UInt64 length)
	{
		Char8* buffer = new Char8[length + 1];
		for (UInt64 i = 0; i < length; i++)
		{
			buffer[i] = *(arr + start + i);
		}

		buffer[length] = 0;
		return buffer;
	}

	[[nodiscard]] static const Char8* ToCharPtr(const std::string& input)
	{
		return Substring(input.c_str(), 0, input.length());
	}

	[[nodiscard]] static const Char8* LoadFile(const Char8* filepath)
	{
		if (!FileExists(filepath))
		{
			std::cerr << "error: unable to locate file: " << filepath << std::endl;
			return nullptr;
		}

		std::ifstream bufferStream(filepath);

		const std::string str = std::string(std::istreambuf_iterator<Char8>(bufferStream), std::istreambuf_iterator<Char8>());
		return ToCharPtr(str);
	}

	[[nodiscard]] static bool IsWhiteSpace(const Char8& ch)
	{
		return isspace(ch);
	}

	[[nodiscard]] static bool IsAlpha(const Char8& ch)
	{
		return ch >= 'a' && ch <= 'z' ||
			   ch >= 'A' && ch <= 'Z' || ch == '_';
	}

	[[nodiscard]] static bool IsDigit(const Char8& ch)
	{
		return ch >= '0' && ch <= '9';
	}

	[[nodiscard]] static bool IsAlphanumeric(const Char8& ch)
	{
		return IsAlpha(ch) || IsDigit(ch);
	}
}
