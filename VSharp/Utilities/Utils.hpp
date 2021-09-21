#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include "Types.hpp"
#include <assert.h>

namespace VSharp::Utilities
{
	#if defined _WIN32 || _WIN64
	constexpr const Types::Char8* NewLine = "\r\n";
	#else
	constexpr const Types::Char8* NewLine = "\n";
	#endif

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

	[[nodiscard]] static bool IsHexDigit(const Types::Char8& ch)
	{
		return (ch >= '0' && ch <= '9') || 
			   (ch >= 'A' && ch <= 'F') ||
			   (ch >= 'a' && ch <= 'f');
	}

	[[nodiscard]] static bool IsBinaryDigit(const Types::Char8& ch)
	{
		return ch == '0' | ch == '1';
	}

	[[nodiscard]] static bool IsDecDigit(const Types::Char8& ch)
	{
		return ch >= '0' && ch <= '9';
	}

	[[nodiscard]] static Types::Int32 HexValue(const Types::Char8& ch)
	{
		assert(IsHexDigit(ch));
		return (ch >= '0' && ch <= '9') ? ch - '0' : (ch & 0xdf) - 'A' + 10;
	}

	[[nodiscard]] static Types::Int32 BinaryDigit(const Types::Char8& ch)
	{
		assert(IsBinaryDigit(ch));
		return ch - '0';
	}

	[[nodiscard]] static Types::Int32 DecValue(const Types::Char8& ch)
	{
		assert(IsDecDigit(ch));
		return ch - '0';
	}

	[[nodiscard]] static bool IsWhiteSpace(const Types::Char8& ch)
	{
		return ch == ' '
			|| ch == '\t'
			|| ch == '\v'
			|| ch == '\f'
			|| ch == '\u00A0'
			|| ch == '\uFEFF'
			|| ch == '\u001A';
			// TODO: support more unicode space separators
	}

	[[nodiscard]] static bool IsNewLine(const Types::Char8& ch)
	{
		return ch == '\r'
			|| ch == '\n'
			|| ch == '\u0085'
			// I'm not sure why I'm getting a clang identical warning?
			|| ch == '\u2028'
			|| ch == '\u2029';
	}

	[[nodiscard]] static bool IsNonAsciiQuotationMark(const Types::Char8& ch)
	{
		return ch == '\u2018' // left single quotation mark
			|| ch == '\u2019' // right single quotation mark
			|| ch == '\u201C' // left double quotation mark
			|| ch == '\u201D'; // right double quotation mark
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
