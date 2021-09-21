#pragma once
#include <vector>
#include "Utilities\Types.hpp"

// TODO: handling metadata

namespace VSharp::Syntax
{
	// This is used to keep track of special type Ids that will be emitted for the .NET CLR
	// You can find Roslyns implementation here -> https://github.com/dotnet/roslyn/blob/main/src/Compilers/Core/Portable/SpecialType.cs
	// We're attempting to keep things easy for when we emit CIL byte-code.
    // Some of the naming conventions have been changed to match VSharps style
    // Anything commented out isn't being emitted currently

    enum class SpecialType : char
    {
        None = 0,
        SystemObject = 1,
        SystemEnum = 2,
        // SystemMulticastDelegate = 3,
        // SystemDelegate = 4,
        SystemValueType = 5,
        SystemVoid = 6,
        SystemBoolean = 7,
        SystemChar = 8,
        SystemInt8 = 9,
        SystemUInt8 = 10,
        SystemInt16 = 11,
        SystemUInt16 = 12,
        SystemInt32 = 13,
        SystemUInt32 = 14,
        SystemInt64 = 15,
        SystemUInt64 = 16,
        SystemDecimal128 = 17,
        SystemFloat32 = 18,
        SystemFloat64 = 19,
        SystemString = 20,
        SystemIntPtr = 21,
        SystemUIntPtr = 22,
        SystemArray = 23,

        // These are under consideration
        // emission will happen later
    	/*SystemCollectionsIEnumerable = 24,
        SystemCollectionsGenericIEnumerable_T = 25, 
        SystemCollectionsGenericIListT = 26,
        SystemCollectionsGenericICollectionT = 27,
        SystemCollectionsIEnumerator = 28,
        SystemCollectionsGenericIEnumeratorT = 29,
        SystemCollectionsGenericIReadOnlyListT = 30,
        SystemCollectionsGenericIReadOnlyCollectionT = 31,
        SystemNullableT = 32,
        SystemDateTime = 33,*/
	};

    static std::vector<const Types::Char8*> EmittedNames
    {
        // Ensure SpecialType enum is kept in sync with this vector
    	nullptr, // SpecialType.None
        "System.Object",
        "System.Enum",
       "System.ValueType",
        "System.Void",
        "System.Boolean",
        "System.Char",
        "System.SByte",
        "System.Byte",
        "System.Int16",
        "System.UInt16",
        "System.Int32",
        "System.UInt32",
        "System.Int64",
        "System.UInt64",
        "System.Decimal",
        "System.Single",
        "System.Double",
        "System.String",
        "System.IntPtr",
        "System.UIntPtr",
        "System.Array",
    };
}