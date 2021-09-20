#include "SyntaxToken.hpp"

namespace VSharp
{
	SyntaxToken::SyntaxToken(const SyntaxKind kind, const unsigned position, const char* text, void* value)
		: Kind(kind), Position(position), Text(text), Value(value) { }
}
