#pragma once

// I hate the fact that the built in types are defined with stupid aliases,
// so I've created typedefs for brevity and clarity sake when working.
namespace VSharp::Types
{
	using Int8 = signed char;
	using UInt8 = unsigned char;

	using Int16 = signed short int;
	using UInt16 = unsigned short int;

	using Int32 = signed int;
	using UInt32 = unsigned int;

	using Int64 = signed long int;
	using UInt64 = unsigned long int;

	using Float32 = float;
	using Float64 = double;
	using Float96 = long double;

	using Char8 = char;
}
