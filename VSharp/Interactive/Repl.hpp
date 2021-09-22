#pragma once
#include <string>
#include "..\Utilities\Types.hpp"

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
			explicit Repl(const bool allowCommands) : AllowCommands(allowCommands) {}

		public:
			const bool AllowCommands;

		public:
			[[nodiscard]] Int32 Execute() const;
			[[nodiscard]] static Int32 ExecuteCommand(const CommandCode code);
			[[nodiscard]] static CommandCode GetCommand(const std::wstring& command);
	};
}

