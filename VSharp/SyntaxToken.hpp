#pragma once
#include "SyntaxKind.hpp"
#include "Types.hpp"

namespace VSharp
{
	class SyntaxToken
	{
		public:
			SyntaxToken(const SyntaxKind kind, const UInt64 position, const Char8* text, void* value) :
				Kind(kind), Position(position), Text(text), Value(value) {}

			SyntaxToken() = default;
			~SyntaxToken() = default;

		public:
			SyntaxKind Kind;
			UInt64 Position;
			const Char8* Text;
			void* Value;
	};
}

