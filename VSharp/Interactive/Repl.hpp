#pragma once
#include <string>
#include <vector>
#include <System\Console.hpp>

#include "System\Integer.hpp"
#include "..\Frontend\Lexer.hpp"

namespace VSharp
{
	namespace Syntax
	{
		class SyntaxToken;
	}
}

namespace VSharp::Interactive
{
	enum class CommandCode
	{
		None = 0,
		Exit = 1,
		ClearScreen = 2,
	};

	class Repl
	{
		public:
			[[nodiscard]] static CommandCode GetCommand(const std::u16string& command)
			{
				if (command == u"#cls")
				{
					// std::cout << "\033[2J\033[1;1H";
					return CommandCode::ClearScreen;
				}
				if (command == u"#exit")
				{
					return CommandCode::Exit;
				}

				return CommandCode::None;
			}

			[[nodiscard]] static System::Int32 ExecuteCommand(const CommandCode code)
			{
				switch (code)
				{
				case CommandCode::None:
					return 0;
				case CommandCode::ClearScreen:
					System::Console::Clear();
					break;
				case CommandCode::Exit:
					return 1;
				}
				return 0;
			}

			[[nodiscard]] static System::Int32 Execute(const bool allowCommands = true)
			{
				while (true)
				{
					try
					{
						System::Console::SetForegroundColor(System::ConsoleColor::Cyan);
						// System::Console::WriteLine("> ");
						// WriteColor("> ", System::ConsoleColor::Cyan);
						std::cout << "> ";
						System::Console::ResetColor();

						std::u16string inputBuffer = System::Console::ReadLine();

						if (inputBuffer.starts_with('#'))
						{
							if (allowCommands)
							{
								const CommandCode code = GetCommand(inputBuffer);
								if (const System::Int32 result = ExecuteCommand(code); result == 1)
								{
									break;
								}
							}
							else
							{
								System::Console::SetForegroundColor(System::ConsoleColor::Red);
								std::cout << "error: unable to execute commands in this repl" << "\n";
								// WriteLineColor("error: unable to execute commands in this repl", System::ConsoleColor::Red);
							}
							continue;
						}

						for (const std::vector<Syntax::SyntaxToken> tokens = Frontend::Lexer::CollectTokens(inputBuffer);
							const Syntax::SyntaxToken & token : tokens)
						{
							System::Console::WriteLine(LookupMemberName(token.Kind));
						}
					}
					catch (const std::exception& ex)
					{
						// Instead of naively catching (..), lets catch the base type,
						// and at least see what went wrong so we don't lose the stack trace.
						System::Console::SetForegroundColor(System::ConsoleColor::Red);
						std::cout << "error: " << ex.what();
					}
				}

				return 0;
			}
	};
}
