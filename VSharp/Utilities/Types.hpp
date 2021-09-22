#pragma once

// I hate the fact that the built in types are defined with stupid aliases,
// so I've created typedefs for brevity and clarity sake when working.

// A utility file that defines all integer types in a reasonable manner,
// specifying size explicitly, along with definitions for their max and min.
// there's official definitions for this but they're named terribly in all caps.
// We don't live in the 80s anymore lmao.

namespace VSharp::Types
{
	// -128 to 127
	using Int8 = int_fast8_t;
	constexpr Int8 Int8Max = 127i8;
	constexpr Int8 Int8Min = -Int8Max;

	// 0 to 255
	using UInt8 = uint_fast8_t;
	constexpr UInt8 UInt8Max = 0xffui8;

	// -32768 to 32767
	using Int16 = int_fast16_t;
	constexpr Int16 Int16Max = 32767i16;
	constexpr Int16 Int16Min = -Int16Max;
	
	// 0 to 65535
	using UInt16 = uint_fast16_t;
	constexpr UInt16 UInt16Max = 0xffffui16;

	// -2,147,483,648 to 2,147,483,647
	using Int32 = int_fast32_t;
	constexpr Int32 Int32Max = 2147483647ui16;
	constexpr Int32 Int32Min = -Int32Max;

	// 0 to 4,294,967,295
	using UInt32 = uint_fast32_t;
	constexpr UInt32 UInt32Max = 0xffffffffui32;

	// -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	using Int64 = int_fast64_t;
	constexpr Int64 Int64Max = 9223372036854775807i64;
	constexpr Int64 Int64Min = -Int64Max;

	// 0 to 18,446,744,073,709,551,615
	using UInt64 = uint_fast64_t;
	constexpr UInt64 UInt64Max = 0xffffffffffffffffui64;

	using Float32 = float;
	constexpr Float32 Float32Max = static_cast<Float32>(3.40282346638528859e+38);
	constexpr Float32 Float32Min = -Float32Max;


	using Float64 = double;
	constexpr Float64 Float64Max = 1.7976931348623157E+308;
	constexpr Float64 Float64Min = -Float64Max;
	// TODO: we need to support Decimal128 for the .NET types

	// -127 to 127
	using Char8 = char; 
	// This is as close as it gets to representing a .NET char type
	// 0 to 65535
	using Char16 = wchar_t; // this isn't necessarily guaranteed to be 16, it could also be 32 depending on platform..
	// similarly known as Rune, at least I think so. Not entirely sure how C++ char types work yet.
	using Char32 = char32_t;
}