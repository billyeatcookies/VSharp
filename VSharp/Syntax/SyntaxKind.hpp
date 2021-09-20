#pragma once

// Corresponding maps and methods located in SyntaxFacts.hpp, holding all the data that defines
// a specific tokens behaviour and its value.
namespace VSharp::Syntax
{
	// | ================== NOTICE ===================== | 
	// | ensure that the corresponding maps and methods  |
	// | are updated with this enum or things WILL fail  |
	// | =============================================== |
	enum class SyntaxKind
	{
		BadToken,
		EndOfFileToken,
		WhiteSpaceToken,
		NewLineToken,
		SingleLineCommentToken,
		MultiLineToken,

		OpenParenToken,
		CloseParenToken,
		OpenBraceToken,
		CloseBraceToken,
		OpenBracketToken,
		CloseBracketToken,

		// Unary
		// these are also unary in single + or - form
		TildeToken,
		BangToken,
		PlusPlusToken,
		MinusMinusToken,

		// Binary operators
		PlusToken,
		MinusToken, // doubles as valid unary operator 
		AsteriskToken,
		FSlashToken,
		PercentToken,
		CaretToken,
		QuestionMarkToken,

		// Compound assignment
		CaretEqualsToken,
		PlusEqualsToken,
		MinusEqualsToken,
		AsteriskEqualsToken,
		FSlashEqualsToken,
		PercentEqualsToken,
		PipeEqualsToken,
		AmpersandEqualsToken,
		LessLessEqualsToken,
		GreaterGreaterEqualsToken,

		BangEqualsToken,
		EqualsToken,
		EqualsEqualsToken,
		LessToken,
		LessEqualsToken,
		GreaterToken,
		GreaterEqualsToken,
		PipeToken,
		PipePipeToken,
		AmpersandToken,
		AmpersandAmpersandToken,

		// Shifts
		LessLessToken,
		GreaterGreaterToken,

		// Separators
		DotToken,
		CommaToken,
		ColonToken,
		SemicolonToken,

		// Compiler reserved keywords
		TypeOfKeyword,
		NameOfKeyword,
		SizeOfKeyword,
		NewKeyword,
		ClassKeyword,
		StructKeyword,
		NilKeyword,
		TrueKeyword,
		FalseKeyword,
		StringKeyword,
		CharKeyword,
		BoolKeyword,
		Int8Keyword,
		UInt8Keyword,
		Int16Keyword,
		UInt16Keyword,
		Int32Keyword,
		UInt32Keyword,
		Int64Keyword,
		UInt64Keyword,
		Float32Keyword,
		Float64Keyword,

		// User defined identifiers, such as:
		// "class Foo {}", or "int8 bar;", this would store just "Foo" or "bar",
		// along with some necessities to bind the identifier properly
		IdentifierToken,

		// Literal values
		// Lexing is the only time we have the easiest access to the literals true type,
		// assigning it to a true literal token will allow us to any_cast<T> the type to
		// the proper .NET type for binding/compilation. Switching enums is also cheaper
		// than type validation :)
		StringLiteralToken,
		CharLiteralToken,
		BoolLiteralToken,
		Int8LiteralToken,
		UInt8LiteralToken,
		Int16LiteralToken,
		UInt16LiteralToken,
		Int32LiteralToken,
		UInt32LiteralToken,
		Int64LiteralToken,
		UInt64LiteralToken,
		Float32LiteralToken,
		Float64LiteralToken,
	};
}