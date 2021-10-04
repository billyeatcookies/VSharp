#pragma once
#include <string>
#include "SyntaxKind.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Syntax
{
	using namespace Types;

	class TokenInfo
	{
		public:
			SyntaxKind Kind;
			std::wstring Text;
			Int32 Start;

			std::any AnyValue;
			std::wstring StringValue;
			Char16 Char16Value;

			Int8 Int8Value;
			UInt8 UInt8Value;
			Int16 Int16Value;
			UInt16 UInt16Value;
			Int32 Int32Value;
			UInt32 UInt32Value;
			Int64 Int64Value;
			UInt64 UInt64Value;

			Float32 Float32Value;
			Float64 Float64Value;
	};
}