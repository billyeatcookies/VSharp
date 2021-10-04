#include "Interactive\Repl.hpp"
using namespace VSharp::Interactive;

Int32 main() noexcept
{
 	return Repl::Execute(true);
}