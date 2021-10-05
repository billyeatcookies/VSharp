#include "Interactive\Repl.hpp"
using namespace VSharp::Interactive;

// Main should always be kept as small as possible for simplistic sake
Int32 main() noexcept
{
 	return Repl::Execute(true);
}