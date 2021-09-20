#pragma once
#include "Types.hpp"

namespace VSharp
{
	enum class TokenFormat
	{
		TextValue,
		NameValue
	};

	enum class SyntaxKind
	{
		BadToken,
		EndOfFileToken,
		NumericLiteralToken,

		OpenParenToken,
		CloseParenToken,
		OpenBraceToken,
		CloseBraceToken,

		PlusToken,
		MinusToken,
		AsteriskToken,
		FSlashToken,
	};

	static const Char8* TokenText(const SyntaxKind& kind);
	static const Char8* TokenName(const SyntaxKind& kind);

	static const Char8* ToString(const SyntaxKind& kind, const TokenFormat& format)
	{
		switch (format)
		{
			case TokenFormat::TextValue:
				return TokenText(kind);
			case TokenFormat::NameValue:
				return TokenName(kind);
			default:
				return "InvalidTokenFormat";
		}
	}

	static const Char8* TokenText(const SyntaxKind& kind)
	{
		switch (kind)
		{
			case SyntaxKind::OpenParenToken:
				return "(";
			case SyntaxKind::CloseParenToken:
				return ")";
			case SyntaxKind::OpenBraceToken:
				return "{";
			case SyntaxKind::CloseBraceToken:
				return "}";
			case SyntaxKind::PlusToken:
				return "+";
			case SyntaxKind::MinusToken:
				return "-";
			case SyntaxKind::AsteriskToken:
				return "*";
			case SyntaxKind::FSlashToken:
				return "/";

			case SyntaxKind::NumericLiteralToken:
				return "NumericLiteralToken";
			default:
				return "";
		}
	}

	static const Char8* TokenName(const SyntaxKind& kind)
	{
		switch (kind)
		{
			// These are handled in the Lexer, they're just covered here for conciseness
			case SyntaxKind::BadToken:
				return "BadToken";

			case SyntaxKind::EndOfFileToken:
				return "EndOfFileToken";
			case SyntaxKind::NumericLiteralToken:
				return "NumericLiteralToken";

			case SyntaxKind::OpenParenToken:
				return "OpenParenToken";
			case SyntaxKind::CloseParenToken:
				return "CloseParenToken";
			case SyntaxKind::OpenBraceToken:
				return "OpenBraceToken";
			case SyntaxKind::CloseBraceToken:
				return "CloseBraceToken";
			case SyntaxKind::PlusToken:
				return "PlusToken";
			case SyntaxKind::MinusToken:
				return "MinusToken";
			case SyntaxKind::AsteriskToken:
				return "AsteriskToken";
			case SyntaxKind::FSlashToken:
				return "FSlashToken";
			default:
				return "InvalidToken";
		}
	}
}