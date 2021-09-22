#include <vector>

#include "Repl.hpp"
#include "ReplColoring.hpp"
#include "..\Syntax\SyntaxToken.hpp"
#include "..\Frontend\Lexer.hpp"

namespace VSharp::Interactive
{
	Int32 Repl::Execute() const
	{
		while (true)
		{
			try
			{
				WriteColor("> ", Colors::Cyan);

				std::wstring inputBuffer;
				std::getline(std::wcin, inputBuffer);

				if (inputBuffer.starts_with('#'))
				{
					if (AllowCommands)
					{
						const CommandCode code = GetCommand(inputBuffer);
						if (const Int32 result = ExecuteCommand(code); result == 1)
						{
							break;
						}
					}
					else
					{
						WriteLineColor("error: unable to execute commands in this repl", Colors::Red);
					}
					continue;
				}

				for (const std::vector<Syntax::SyntaxToken> tokens = Frontend::Lexer::CollectTokens(inputBuffer);
				     const Syntax::SyntaxToken & token : tokens)
				{
					std::wcout << LookupMemberName(token.Kind) << std::endl;
				}
			}
			catch (...)
			{
				// tired of seeing crash messages so I just use this to stop it,
				// and print so I at least know something went wrong
				std::cout << "main threw an exception" << std::endl;
			}
		}

		return 0;
	}

	CommandCode Repl::GetCommand(const std::wstring& command)
	{
		if (command == L"#cls")
		{
			// std::cout << "\033[2J\033[1;1H";
			return CommandCode::ClearScreen;
		}
		if (command == L"#exit")
		{
			return CommandCode::Exit;
		}

		return CommandCode::None;
	}

	Int32 Repl::ExecuteCommand(const CommandCode code)
	{
		switch (code)
		{
			case CommandCode::None:
				return 0;
			case CommandCode::ClearScreen:
				std::cout << "\033[2J\033[1;1H";
				break;
			case CommandCode::Exit:
				return 1;
		}
		return 0;
	}
}
