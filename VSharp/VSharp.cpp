#include <iostream>
#include <string>
#include "Lexer.hpp"
#include "Types.hpp"

using namespace VSharp;
int main() noexcept
{
	while (true)
	{
		try
		{
			std::cout << "> ";

			std::string inputBuffer;
			std::getline(std::cin, inputBuffer);

			const SyntaxToken* tokens = Lexer::CollectTokens(inputBuffer.c_str());
			for (UInt64 i = 0; i < sizeof(&tokens); i++)
			{
				std::cout << ToString(tokens[i].Kind, TokenFormat::NameValue) << std::endl;
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
