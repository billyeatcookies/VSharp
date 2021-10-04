#pragma once
#include <iostream>
#include <string>
#include "..\Utilities\Types.hpp"
#include <Windows.h> 

namespace VSharp::Interactive
{
	using namespace Types;

	enum class Colors : UInt8
	{
		Black = 0,
		DarkBlue = 1,
		DarkGreen = 2,
		LightBlue = 3,
		DarkRed = 4,
		Magenta = 5,
		Orange = 6,
		LightGray = 7,
		Gray = 8,
		Blue = 9,
		Green = 10,
		Cyan = 11,
		Red = 12,
		Pink = 13,
		Yellow = 14,
		White = 15
	};

	[[nodiscard]] static std::string GetTextColorCode(const Colors textColor)
	{
		switch (textColor)
		{
	        case Colors::Black:     return "30"; // color_black      0
	        case Colors::DarkBlue:  return "34"; // color_dark_blue  1
	        case Colors::DarkGreen: return "32"; // color_dark_green 2
	        case Colors::LightBlue: return "36"; // color_light_blue 3
	        case Colors::DarkRed:   return "31"; // color_dark_red   4
	        case Colors::Magenta:   return "35"; // color_magenta    5
	        case Colors::Orange:    return "33"; // color_orange     6
	        case Colors::LightGray: return "37"; // color_light_gray 7
	        case Colors::Gray:      return "90"; // color_gray       8
			case Colors::Blue:      return "94"; // color_blue       9
	        case Colors::Green:     return "92"; // color_green     10
	        case Colors::Cyan:      return "96"; // color_cyan      11
	        case Colors::Red:       return "91"; // color_red       12
	        case Colors::Pink:      return "95"; // color_pink      13
	        case Colors::Yellow:    return "93"; // color_yellow    14
	        case Colors::White:     return "97"; // color_white     15
		}
		return "37";
	}

	[[nodiscard]] static std::string GetBackgroundColorCode(const Colors backgroundColor)
	{
		switch (backgroundColor)
		{
			case Colors::Black:     return "40"; // color_black      0
			case Colors::DarkBlue:  return "44"; // color_dark_blue  1
			case Colors::DarkGreen: return "42"; // color_dark_green 2
			case Colors::LightBlue: return "46"; // color_light_blue 3
			case Colors::DarkRed:   return "41"; // color_dark_red   4
			case Colors::Magenta:   return "45"; // color_magenta    5
			case Colors::Orange:    return "43"; // color_orange     6
			case Colors::LightGray: return "47"; // color_light_gray 7
			case Colors::Gray:      return "100"; // color_gray       8
			case Colors::Blue:      return "104"; // color_blue       9
			case Colors::Green:     return "102"; // color_green     10
			case Colors::Cyan:      return "106"; // color_cyan      11
			case Colors::Red:       return "101"; // color_red       12
			case Colors::Pink:		return "105"; // color_pink      13
			case Colors::Yellow:	return "103"; // color_yellow    14
			case Colors::White:		return "107"; // color_white     15
		}
		return "40";
	}

	[[nodiscard]] static std::string GetColor(const Colors textColor)
	{
		return "\033[" + GetTextColorCode(textColor) + "m";
	}

	[[nodiscard]] static std::string GetColor(const Colors textColor, const Colors bgColor)
	{
		return "\033" + GetTextColorCode(textColor) + ";" + GetBackgroundColorCode(bgColor) + "m";
	}

	static void WriteColor(const Colors textColor)
	{
		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, static_cast<Int8>(textColor));
	}

	static void WriteColor(const Colors textColor, const Colors bgColor)
	{
		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, static_cast<UInt8>(static_cast<UInt8>(bgColor) << static_cast<UInt8>(4) | static_cast<UInt8>(textColor)));
	}

	static void ResetColor()
	{
		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 7);
	}

	static void WriteLine(const std::string& input)
	{
		std::cout << input << std::endl;
	}

	static void Write(const std::string& input)
	{
		std::cout << input;
	}

	static void WriteLineColor(const std::string& input, const Colors textColor)
	{
		WriteColor(textColor);
		WriteLine(input);
		ResetColor();
	}

	static void WriteColor(const std::string& input, const Colors textColor)
	{
		WriteColor(textColor);
		Write(input);
		ResetColor();
	}

}