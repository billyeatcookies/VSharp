#pragma once

namespace VSharp
{
	static Char8* Substring(const Char8* arr, const UInt64 start, const UInt64 length)
	{
		Char8* buffer = new Char8[length + 1];
		for (UInt64 i = 0; i < length; i++)
		{
			buffer[i] = *(arr + start + i);
		}
		buffer[length] = 0;
		return buffer;
	}

	static bool IsWhiteSpace(const Char8& ch)
	{
		return isspace(ch);
	}

	static bool IsAlpha(const Char8& ch)
	{
		return ch >= 'a' && ch <= 'z' ||
			   ch >= 'A' && ch <= 'Z' || ch == '_';
	}

	static bool IsDigit(const Char8& ch)
	{
		return ch >= '0' && ch <= '9';
	}

	static bool IsAlphanumeric(const Char8& ch)
	{
		return IsAlpha(ch) || IsDigit(ch);
	}
}