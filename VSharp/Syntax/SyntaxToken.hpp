#pragma once
#include <any>

#include "SyntaxFacts.hpp"
#include "System\Integer.hpp"

namespace VSharp::Syntax
{
	class SyntaxToken
	{
		public:
			SyntaxToken(const SyntaxKind kind, const System::UInt64 position, std::u16string text, std::any value) :
				Kind(kind), Position(position), Text(std::move(text)), Value(std::move(value)) {}
			
			SyntaxToken() : Kind(SyntaxKind::BadToken), Position(0), Text(), Value(nullptr) {}

		public:
			SyntaxKind Kind;
			System::UInt64 Position;
			std::u16string Text;
			std::any Value;
	};
}