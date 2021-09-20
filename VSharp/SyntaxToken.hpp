#pragma once
#include <any>
#include "SyntaxFacts.hpp"
#include "Types.hpp"

namespace VSharp
{
	class SyntaxToken
	{
		public:
			SyntaxToken(const SyntaxKind kind, const UInt64 position, const Char8* text, std::any value) :
				Kind(kind), Position(position), Text(text), Value{std::move(value)} {}
			
			SyntaxToken() : Kind(SyntaxKind::BadToken), Position(0), Text(nullptr), Value(nullptr) {}

		public:
			SyntaxKind Kind;
			UInt64 Position;
			const Char8* Text;
			std::any Value;
	};
}