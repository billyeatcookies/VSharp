#pragma once

// I hate the fact that the built in types are defined with stupid aliases,
// so I've created typedefs for brevity and clarity sake when working.
namespace VSharp::Types
{
	// -128 to 127
	using Int8 = int_fast8_t;
	// 0 to 255
	using UInt8 = uint_fast8_t;

	// -32768 to 32767
	using Int16 = int_fast16_t;
	// 0 to 65535
	using UInt16 = uint_fast16_t;

	// -2,147,483,648 to 2,147,483,647
	using Int32 = int_fast32_t;
	// 0 to 4,294,967,295
	using UInt32 = uint_fast32_t;

	// -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	using Int64 = int_fast64_t;
	// 0 to 18,446,744,073,709,551,615
	using UInt64 = int_fast64_t;

	using Float32 = float;
	using Float64 = double;

	using Char8 = char; // 127
	// This is as close as it gets to representing a .NET char type
	using Char16 = unsigned short int; // 65535
	// similarly known as Rune
	using Char32 = char32_t;

	// Narrowing conversion warnings
	static constexpr Char8 Char8MaxValue = static_cast<Char8>(0xff);
	static constexpr Char16 Char16MaxValue = static_cast<Char16>(0xFFFF);
	static constexpr Char32 Char32MaxValue = 0x7fffffff; // already int32 max
}
