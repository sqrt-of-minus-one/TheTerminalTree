////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: style.h                     //
////////////////////////////////////////

#pragma once

#include <ostream>

// A more convenient way to apply stiles to the text in the console

namespace ui
{

// Possible colours
enum class EColour
{
	DEFAULT,
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
	BRIGHT_BLACK, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW, BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE
};
EColour string_to_colour(const std::string& str);

// Blinking types
enum class EBlinking
{
	OFF, SLOW, RAPID
};
EBlinking string_to_blinking(const std::string& str);

// Underlining types
enum class EUnderline
{
	OFF, SINGLE, DOUBLE
};
EUnderline string_to_underline(const std::string& str);

namespace style
{

// Codes of the colours of text
namespace text_colour
{
	extern const int BLACK;
	extern const int RED;
	extern const int GREEN;
	extern const int YELLOW;
	extern const int BLUE;
	extern const int MAGENTA;
	extern const int CYAN;
	extern const int WHITE;
	extern const int BRIGHT_BLACK;
	extern const int BRIGHT_RED;
	extern const int BRIGHT_GREEN;
	extern const int BRIGHT_YELLOW;
	extern const int BRIGHT_BLUE;
	extern const int BRIGHT_MAGENTA;
	extern const int BRIGHT_CYAN;
	extern const int BRIGHT_WHITE;
	extern const int DEFAULT;
}
int get_text_colour_code(EColour text_colour);

// Codes of the colours of background
namespace back_colour
{
	extern const int BLACK;
	extern const int RED;
	extern const int GREEN;
	extern const int YELLOW;
	extern const int BLUE;
	extern const int MAGENTA;
	extern const int CYAN;
	extern const int WHITE;
	extern const int BRIGHT_BLACK;
	extern const int BRIGHT_RED;
	extern const int BRIGHT_GREEN;
	extern const int BRIGHT_YELLOW;
	extern const int BRIGHT_BLUE;
	extern const int BRIGHT_MAGENTA;
	extern const int BRIGHT_CYAN;
	extern const int BRIGHT_WHITE;
	extern const int DEFAULT;
}
int get_back_colour_code(EColour back_colour);

// Codes of other styles
extern const int RESET;
extern const int BOLD;
extern const int BOLD_OFF;
extern const int ITALIC;
extern const int ITALIC_OFF;
extern const int UNDERLINE_SINGLE;
extern const int UNDERLINE_DOUBLE;
extern const int UNDERLINE_OFF;
extern const int BLINKING_SLOW;
extern const int BLINKING_RAPID;
extern const int BLINKING_OFF;
extern const int REVERSE_COLOURS;
extern const int REVERSE_COLOURS_OFF;
extern const int CROSS_OUT;
extern const int CROSS_OUT_OFF;

int get_blinking_code(EBlinking blinking);
int get_underline_code(EUnderline underline);

}

}