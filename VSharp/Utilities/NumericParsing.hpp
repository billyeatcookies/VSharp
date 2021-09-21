#pragma once
#include <tuple>
#include "Types.hpp"

namespace VSharp::Utilities
{
	static std::tuple<Types::Int64, bool> TryParseI64(const Types::Char8* value)
	{
		if (std::strlen(value) == 0)
		{
			return std::make_tuple(0, false);
		}

		bool isNeg = false;
		Types::Int64 result = 0;

		for (Types::UInt32 i = 0; i < std::strlen(value); i++)
		{
			const Types::Char8 ch = value[i];
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

	static std::tuple<Types::UInt64, bool> TryParseUI64(const Types::Char8* value)
	{
		if (std::strlen(value) == 0)
		{
			return std::make_tuple(0, false);
		}

		Types::UInt64 result = 0;
		for (Types::UInt64 i = 0; i < std::strlen(value); i++)
		{
			const Types::Char8 c = value[i];
			if ((i == 0) && (c == '-'))
			{
				return std::make_tuple(0, false);
			}
			if ((c >= '0') && (c <= '9'))
			{
				result *= 10;
				result += static_cast<Types::UInt64>(c - '0');
			}
			else
			{
				return std::make_tuple(0, false);
			}
		}
		return std::make_tuple(result, true);
	}

	static std::tuple<Types::Int32, bool> TryParseI32(const Types::Char8* value)
	{
		if (std::strlen(value))
		{
			return std::make_tuple(0, false);
		}

		bool isNeg = false;
		Types::Int32 result = 0;

		for (Types::UInt32 i = 0; i < std::strlen(value); i++)
		{
			const Types::Char8 ch = value[i];
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

	static std::tuple<Types::UInt32, bool> TryParseUI32(const Types::Char8* value)
	{
		if (std::strlen(value) == 0)
		{
			return std::make_tuple(0, false);
		}

		Types::UInt32 result = 0;
		for (Types::UInt32 i = 0; i < std::strlen(value); i++)
		{
			const Types::Char8 ch = value[i];
			if (i == 0 && ch == '-')
			{
				return std::make_tuple(0, false);
			}
			if (ch >= '0' && ch <= '9')
			{
				result *= 10;
				result += static_cast<Types::UInt32>(ch - '0');
			}
			else
			{
				return std::make_tuple(0, false);
			}
		}
		return std::make_tuple(result, false);
	}

	static std::tuple<Types::Int16, bool> TryParseI16(const Types::Char8* value)
	{
		return TryParseI32(value);
	}

	static std::tuple<Types::UInt16, bool> TryParseUI16(const Types::Char8* value)
	{
		return TryParseUI32(value);
	}

	static std::tuple<Types::Int8, bool> TryParseI8(const Types::Char8* value)
	{
		return TryParseI16(value);
	}

	static std::tuple<Types::UInt8, bool> TryParseUI8(const Types::Char8* value)
	{
		return TryParseUI16(value);
	}
}