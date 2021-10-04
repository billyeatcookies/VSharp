#pragma once
#include <any>
#include "SyntaxFacts.hpp"
#include "TokenInfo.hpp"
#include "..\Utilities\Types.hpp"

namespace VSharp::Syntax
{
	class SyntaxToken
	{
		public:
			SyntaxToken(const TokenInfo& info, const UInt64 position) :
				Kind(info.Kind), Position(position), Text(info.Text), Value(info.AnyValue) {}

			SyntaxToken(const SyntaxKind kind, const UInt64 position, std::wstring text, std::any value) :
				Kind(kind), Position(position), Text(std::move(text)), Value(std::move(value)) {}
			
			SyntaxToken() : Kind(SyntaxKind::BadToken), Position(0), Text(), Value(nullptr) {}

		public:
			SyntaxKind Kind;
			UInt64 Position;
			std::wstring Text;
			std::any Value;
	};
}