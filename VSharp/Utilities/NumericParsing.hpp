#pragma once
#include <tuple>
#include <string>
#include "Types.hpp"
#include "Utils.hpp"

namespace VSharp::Utilities
{
	using namespace Types;

	static std::string WToString(const std::wstring& input)
	{
		std::string str;
		std::ranges::transform(input, std::back_inserter(str), [](const Char16 c)
		{
			return static_cast<Char8>(c);
		});
		
		return str;
	}

	static std::tuple<Int64, bool> TryParseI64(const std::wstring& value)
	{
		if (value.length() == 0)
		{
			return std::make_tuple(0, false);
		}

		bool isNeg = false;
		Int64 result = 0;

		for (UInt32 i = 0; i < value.length(); i++)
		{
			const Char16 ch = value[i];
			if (i == 0 && ch == '-')
			{
				isNeg = true;
				continue;
			}
			if (ch >= '0' && ch <= '9')
			{
				result *= 10;
				result += ch - '0'; // TODO: possible overflow fixing
			}
			else if (ch == '\'')
			{
				// ignore
			}
			else
			{
				return std::make_tuple(0, false);
			}
		}
		
		return std::make_tuple(isNeg ? -result : result, true);
	}

	static std::tuple<UInt64, bool> TryParseUI64(const std::wstring& value)
	{
		if (value.length() == 0)
		{
			return std::make_tuple(0, false);
		}

		UInt64 result = 0;
		for (UInt32 i = 0; i < value.length(); i++)
		{
			const Char16 c = value[i];
			if ((i == 0) && (c == '-'))
			{
				return std::make_tuple(0, false);
			}
			if ((c >= '0') && (c <= '9'))
			{
				result *= 10;
				result += static_cast<UInt64>(c - '0');
			}
			else
			{
				return std::make_tuple(0, false);
			}
		}
		return std::make_tuple(result, true);
	}

	static std::tuple<Int32, bool> TryParseI32(const std::wstring& value)
	{
		if (value.length() == 0)
		{
			return std::make_tuple(0, false);
		}

		bool isNeg = false;
		Int32 result = 0;

		for (UInt32 i = 0; i < value.length(); i++)
		{
			const Char16 ch = value[i];
			if (i == 0 && ch == '-')
			{
				isNeg = true;
				continue;
			}
			if (ch >= '0' && ch <= '9')
			{
				result *= 10;
				result += ch - 'A' + 10;
			}
			else if (ch == '\'')
			{
				// ignored
			}
			else
			{
				return std::make_tuple(0, false);
			}
		}

		return std::make_tuple(isNeg ? -result : result, true);
	}

	static std::tuple<UInt32, bool> TryParseUI32(const std::wstring& value)
	{
		if (value.length() == 0)
		{
			return std::make_tuple(0, false);
		}

		UInt32 result = 0;
		for (UInt32 i = 0; i < value.length(); i++)
		{
			const Char16 ch = value[i];
			if (i == 0 && ch == '-')
			{
				return std::make_tuple(0, false);
			}
			if (ch >= '0' && ch <= '9')
			{
				result *= 10;
				result += static_cast<UInt32>(ch - '0');
			}
			else
			{
				return std::make_tuple(0, false);
			}
		}
		return std::make_tuple(result, false);
	}

	static std::tuple<Int16, bool> TryParseI16(const std::wstring& value)
	{
		const std::tuple result = TryParseUI32(value);
		return std::make_tuple(static_cast<Int16>(std::get<0>(result)), std::get<1>(result));
	}

	static std::tuple<UInt16, bool> TryParseUI16(const std::wstring& value)
	{
		const std::tuple result = TryParseUI32(value);
		return std::make_tuple(static_cast<UInt16>(std::get<0>(result)), std::get<1>(result));
	}

	static std::tuple<Int8, bool> TryParseI8(const std::wstring& value)
	{
		const std::tuple result = TryParseI32(value);
		return std::make_tuple(static_cast<Int8>(std::get<0>(result)), std::get<1>(result));
	}

	static std::tuple<UInt8, bool> TryParseUI8(const std::wstring& value)
	{
		const std::tuple result = TryParseI32(value);
		return std::make_tuple(static_cast<UInt8>(std::get<0>(result)), std::get<1>(result));
	}

	static std::tuple<Float64, bool> TryParseF64(const std::wstring& wstr, Char8** ptr = nullptr)
	{
		try
		{
			std::string str = WToString(wstr);
			if (ptr == static_cast<Char8**>(nullptr))
			{
				return std::make_tuple(std::strtod(str.c_str(), nullptr), true);
			}

			Char8* p = str.data();

			while (IsWhiteSpace(*p))
			{
				++p;
			}

			if (*p == '+' || *p == '-')
			{
				++p;
			}

			// INF or INFINITY. 
			if ((p[0] == 'i' || p[0] == 'I')
			 && (p[1] == 'n' || p[1] == 'N')
			 && (p[2] == 'f' || p[2] == 'F'))
			{
				if ((p[3] == 'i' || p[3] == 'I')
				 && (p[4] == 'n' || p[4] == 'N')
				 && (p[5] == 'i' || p[5] == 'I')
				 && (p[6] == 't' || p[6] == 'T')
				 && (p[7] == 'y' || p[7] == 'Y'))
				{
					*ptr = p + 8;
					return std::make_tuple(std::strtod(str.c_str(), nullptr), true);
				}

				*ptr = p + 3;
				return std::make_tuple(std::strtod(str.c_str(), nullptr), true);
			}
			// NAN or NAN(foo).
			if ((p[0] == 'n' || p[0] == 'N')
			 && (p[1] == 'a' || p[1] == 'A')
			 && (p[2] == 'n' || p[2] == 'N'))
			{
				p += 3;
				if (*p == '(')
				{
					++p;
					while (*p != '\0' && *p != ')')
					{
						++p;
					}
					if (*p == ')')
					{
						++p;
					}
				}
				*ptr = p;
				return std::make_tuple(std::strtod(str.c_str(), nullptr), true);
			}
			// digits, with 0 or 1 periods in it. 
			if (IsDigit(*p) || *p == '.')
			{
				bool hasDecimal = false;
				while (IsDigit(*p) || (!hasDecimal && *p == '.'))
				{
					if (*p == '.')
					{
						hasDecimal = true;
					}
					++p;
				}

				// Exponent.  
				if (*p == 'e' || *p == 'E')
				{
					Int32 i = 1;
					if (p[i] == '+' || p[i] == '-')
					{
						++i;
					}
					if (IsDigit(p[i]))
					{
						while (IsDigit(p[i]))
						{
							++i;
						}

						*ptr = p + i;
						return std::make_tuple(std::strtod(str.c_str(), nullptr), true);
					}
				}

				*ptr = p;
				return std::make_tuple(std::strtod(str.c_str(), nullptr), true);
			}

			// Didn't find any digits. Doesn't look like a number. 
			*ptr = str.data();
			return std::make_tuple(0.0, false);
		}
		catch (...)
		{
			return std::make_tuple(0.0, false);
		}
	}

	static std::tuple<Float32, bool> TryParseF32(const std::wstring& input, Char8** ptr = nullptr)
	{
		const std::tuple result = TryParseF64(input, ptr);
		return std::make_tuple(static_cast<Float32>(std::get<0>(result)), std::get<1>(result));
	}


	static std::tuple<UInt64, bool> TryParseBinaryUInt64(const std::wstring& text)
	{
		UInt64 value = 0;
		for (const Char16& chr : text)
		{
			if ((value & 0x8000000000000000) != 0)
			{
				return std::make_tuple(0, false);
			}

			const UInt64 bit = BinaryValue(chr);
			value = (value << 1) | bit;
		}

		return std::make_tuple(value, false);
	}
}