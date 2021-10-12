#include "System\Integer.hpp"
#include "Interactive\Repl.hpp"

// Main should always be kept as small as possible for simplistic sake
System::Int32 main() noexcept
{
	return VSharp::Interactive::Repl::Execute();
}