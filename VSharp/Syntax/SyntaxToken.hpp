#pragma once
#include <any>
#include "SyntaxFacts.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Syntax
{
	class SyntaxToken
	{
		public:
			SyntaxToken(const SyntaxKind kind, const Types::UInt64 position, const Types::Char8* text, std::any value) :
				Kind(kind), Position(position), Text(text), Value{std::move(value)} {}
			
			SyntaxToken() : Kind(SyntaxKind::BadToken), Position(0), Text(nullptr), Value(nullptr) {}

		public:
			SyntaxKind Kind;
			Types::UInt64 Position;
			const Types::Char8* Text;
			std::any Value;
	};
}