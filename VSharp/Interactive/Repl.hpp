#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "ReplColoring.hpp"
#include "..\Utilities\Types.hpp"
#include "..\Syntax\SyntaxToken.hpp"
#include "..\Frontend\Lexer.hpp"

namespace VSharp::Interactive
{
	using namespace Types;

	enum class CommandCode
	{
		None = 0,
		Exit = 1,
		ClearScreen = 2,
	};

	class Repl
	{
		public:
			[[nodiscard]] static CommandCode GetCommand(const std::wstring& command)
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

			[[nodiscard]] static Int32 ExecuteCommand(const CommandCode code)
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

			[[nodiscard]] static Int32 Execute(const bool allowCommands = true)
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
							if (allowCommands)
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
					catch (const std::exception& ex)
					{
						// Instead of naively catching (..), lets catch the base type,
						// and at least see what went wrong so we don't lose the stack trace.
						WriteColor("error: ", Colors::Red);
						WriteColor(ex.what(), Colors::Red);
					}
				}

				return 0;
			}
	};
}