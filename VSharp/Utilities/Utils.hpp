#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include "Types.hpp"
#include <cassert>

namespace VSharp::Utilities
{
	using namespace Types;

	#if defined _WIN32 || _WIN64
	constexpr const Char8* NewLine = "\r\n";
	#else
	constexpr const Char8* NewLine = "\n";
	#endif

	[[nodiscard]] static const Char8* Substring(const Char8* input, const UInt32 start, const UInt32 length)
	{
		Char8* buffer = new Char8[static_cast<UInt32>(length + 1ui64)];
		for (UInt32 i = 0; i < length; i++)
		{
			buffer[i] = *(input + start + i);
		}
		
		buffer[length] = 0;
		return buffer;
	}

	[[nodiscard]] static const Char8* ToCharPtr(const std::string& input)
	{
		return Substring(input.c_str(), 0, input.length());
	}
	
	[[nodiscard]] static bool FileExists(const Char8* filepath)
	{
		return std::filesystem::exists(filepath);
	}

	[[nodiscard]] static const Char8* LoadFile(const Char8* filepath)
	{
		if (!FileExists(filepath))
		{
			std::cerr << "error: unable to locate file: " << filepath << std::endl;
			return nullptr;
		}

		std::ifstream bufferStream(filepath);
		const std::string text = std::string(std::istreambuf_iterator<Char8>(bufferStream), std::istreambuf_iterator<Char8>());
		return ToCharPtr(text);
	}

	[[nodiscard]] static bool IsHexDigit(const Char8& ch)
	{
		return (ch >= '0' && ch <= '9') || 
			   (ch >= 'A' && ch <= 'F') ||
			   (ch >= 'a' && ch <= 'f');
	}

	[[nodiscard]] static bool IsBinaryDigit(const Char8& ch)
	{
		return (ch == '0') | (ch == '1');
	}

	[[nodiscard]] static bool IsDecDigit(const Char8& ch)
	{
		return ch >= '0' && ch <= '9';
	}

	[[nodiscard]] static Int32 HexValue(const Char8& ch)
	{
		assert(IsHexDigit(ch));
		return (ch >= '0' && ch <= '9') ? ch - '0' : (ch & 0xdf) - 'A' + 10;
	}

	[[nodiscard]] static Int32 BinaryDigit(const Char8& ch)
	{
		assert(IsBinaryDigit(ch));
		return ch - '0';
	}

	[[nodiscard]] static Int32 DecValue(const Char8& ch)
	{
		assert(IsDecDigit(ch));
		return ch - '0';
	}

	[[nodiscard]] static bool IsWhiteSpace(const Char8& ch)
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

	[[nodiscard]] static bool IsNewLine(const Char8& ch)
	{
		return ch == '\r'
			|| ch == '\n'
			|| ch == '\u0085';
	}

	[[nodiscard]] static bool IsNonAsciiQuotationMark(const Char8& ch)
	{
		return ch == '\u2018' // left single quotation mark
			|| ch == '\u2019' // right single quotation mark
			|| ch == '\u201C' // left double quotation mark
			|| ch == '\u201D'; // right double quotation mark
	}

	// TODO: Support more unicode? What happens if someone writes code in Russian or Chinese?
	[[nodiscard]] static bool IsAlpha(const Char8& ch)
	{
		return ch >= 'a' && ch <= 'z' ||
			   ch >= 'A' && ch <= 'Z' || ch == '_';
	}

	// My own IsDigit that just checks the character directly because I don't like built in
	[[nodiscard]] static bool IsDigit(const Char8& ch)
	{
		return ch >= '0' && ch <= '9';
	}

	// Used for identifying keywords and identifiers, since identifiers can contain numbers and underscores
	// NOTICE: don't use this until you've used IsAlpha(ch) to ENSURE that the first character is an underscore
	// or valid ASCII character.
	[[nodiscard]] static bool IsAlphanumeric(const Char8& ch)
	{
		return IsAlpha(ch) || IsDigit(ch);
	}
}
