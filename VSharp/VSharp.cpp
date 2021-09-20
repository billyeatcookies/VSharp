#include <iostream>
#include <string>
#include "Frontend\Lexer.hpp"
#include "Utilities\Utils.hpp"

using namespace VSharp;
void ExecuteCommand(const std::string& command);
Types::Int32 ExecuteRepl();
Types::Int32 ExecuteFile(const char* filepath);


int main(int argc, char* argv[]) noexcept
{
	return ExecuteRepl();
	/*if (argc == 0)
	{
	}
	if (argc == 1)
	{
		return ExecuteFile(argv[0]);
	}*/
}

void ExecuteCommand(const std::string& command)
{
	#if defined _WIN32 || defined _WIN64_
	if (command == "#cls")
	{
		// breakdown:
		// \033[2J: clears the entire screen (J) from top to bottom (2)
		// \033[1;1H: positions the cursor at row (1), and column (1).
		std::cout << "\033[2J\033[1;1H";
	}
	#else
	std::cout << "#cls isn't supported on your platform" << std::endl;
	#endif

	if (command == "#exit")
	{
		exit(0);
	}
}

Types::Int32 ExecuteFile(const char* filepath)
{
	if (!Utilities::FileExists(filepath))
	{
		std::cerr << "unable to locate '" << filepath << "'" << std::endl;
		return 1;
	}
	
	const char* input = Utilities::LoadFile(filepath);
	for (const std::vector<Syntax::SyntaxToken> tokens = Frontend::Lexer::CollectTokens(Utilities::ToCharPtr(input));
		const Syntax::SyntaxToken & token : tokens)
	{
		std::cout << Syntax::LookupMemberName(token.Kind) << std::endl;
	}

	std::cout << "Press any key to continue...";
	std::cin;
	return 0;
}

Types::Int32 ExecuteRepl()
{
	while (true)
	{
		try
		{
			std::cout << "> ";

			std::string inputBuffer;
			std::getline(std::cin, inputBuffer);

			if (inputBuffer.starts_with('#'))
			{
				ExecuteCommand(inputBuffer);
				continue;
			}

			for (const std::vector<Syntax::SyntaxToken> tokens = Frontend::Lexer::CollectTokens(Utilities::ToCharPtr(inputBuffer));
				const Syntax::SyntaxToken & token : tokens)
			{
				std::cout << Syntax::LookupMemberName(token.Kind) << std::endl;
			}
		}
		catch (...)
		{
			// tired of seeing crash messages so I just use this to stop it,
			// and print so I at least know something went wrong
			std::cout << "main threw an exception" << std::endl;
		}
	}
}
