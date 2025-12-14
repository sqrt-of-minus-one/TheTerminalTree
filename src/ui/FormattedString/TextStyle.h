////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: TestStyle.h                 //
////////////////////////////////////////

#pragma once

#include "../style.h"

#include <optional>

namespace ui
{

// The text style can be applied to the output stream. E.g. after
//		std::cout << TextStyle { .bold = true, .underline = EUnderline::SINGLE };
// the text put in std::cout will be bold and underlined. Use
//		std::cout << TextStyle::DEFAULT
// to restore the default style
struct TextStyle
{
	// All values are optional. If a value is absent, the previous setting for it will be used
	std::optional<EColour> text_colour;
	std::optional<EColour> back_colour;
	std::optional<EBlinking> blinking;
	std::optional<bool> bold;
	std::optional<bool> italic;
	std::optional<EUnderline> underline;
	std::optional<bool> cross_out;

	// Reverts the style so that the default style would be restored
	TextStyle operator~() const;

	// Combines two styles.
	//		std::cout << style1 + style2;
	// does the same as
	//		std::cout << style1 << style2;
	TextStyle operator+(const TextStyle& style) const;
	TextStyle& operator+=(const TextStyle& style);

	// (style1 - style2) is the style that needs to be applied after style1 in order to restore style2
	// This means that after
	//		std::cout << style2;
	// the line
	//		std::cout << style1 << style1 - style2;
	// changes nothing
	TextStyle operator-(const TextStyle& style) const;
	TextStyle& operator-=(const TextStyle& style);

	// The default text style
	static TextStyle DEFAULT;
};
std::ostream& operator<<(std::ostream& stream, const TextStyle& style);

}
