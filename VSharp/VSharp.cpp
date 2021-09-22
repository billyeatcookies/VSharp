#include "Interactive\Repl.hpp"

using namespace VSharp::Interactive;

int main() noexcept
{
	Repl repl = Repl(true);
	return repl.Execute();
}
