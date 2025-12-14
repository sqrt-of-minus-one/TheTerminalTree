////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: style.cpp                   //
////////////////////////////////////////

#include "style.h"

using namespace ui;

EColour ui::string_to_colour(const std::string& str)
{
		 if (str == "black")			return EColour::BLACK;
	else if (str == "red")				return EColour::RED;
	else if (str == "green")			return EColour::GREEN;
	else if (str == "yellow")			return EColour::YELLOW;
	else if (str == "blue")				return EColour::BLUE;
	else if (str == "magenta")			return EColour::MAGENTA;
	else if (str == "cyan")				return EColour::CYAN;
	else if (str == "white")			return EColour::WHITE;
	else if (str == "bright_black")		return EColour::BRIGHT_BLACK;
	else if (str == "bright_red")		return EColour::BRIGHT_RED;
	else if (str == "bright_green")		return EColour::BRIGHT_GREEN;
	else if (str == "bright_yellow")	return EColour::BRIGHT_YELLOW;
	else if (str == "bright_blue")		return EColour::BRIGHT_BLUE;
	else if (str == "bright_magenta")	return EColour::BRIGHT_MAGENTA;
	else if (str == "bright_cyan")		return EColour::BRIGHT_CYAN;
	else if (str == "bright_white")		return EColour::BRIGHT_WHITE;
	else								return EColour::DEFAULT;
}

EBlinking ui::string_to_blinking(const std::string& str)
{
		 if (str == "slow")		return EBlinking::SLOW;
	else if (str == "rapid")	return EBlinking::RAPID;
	else						return EBlinking::OFF;
}

EUnderline ui::string_to_underline(const std::string& str)
{
		 if (str == "single")	return EUnderline::SINGLE;
	else if (str == "double")	return EUnderline::DOUBLE;
	else						return EUnderline::OFF;
}

constexpr int BLACK_	= 0;
constexpr int RED_		= 1;
constexpr int GREEN_	= 2;
constexpr int YELLOW_	= 3;
constexpr int BLUE_		= 4;
constexpr int MAGENTA_	= 5;
constexpr int CYAN_		= 6;
constexpr int WHITE_	= 7;
constexpr int DEFAULT_	= 9;
constexpr int TEXT_		= 30;
constexpr int BACK_		= 40;
constexpr int BRIGHT_	= 60;

constexpr int style::text_colour::BLACK				= TEXT_ + BLACK_;
constexpr int style::text_colour::RED				= TEXT_ + RED_;
constexpr int style::text_colour::GREEN				= TEXT_ + GREEN_;
constexpr int style::text_colour::YELLOW			= TEXT_ + YELLOW_;
constexpr int style::text_colour::BLUE				= TEXT_ + BLUE_;
constexpr int style::text_colour::MAGENTA			= TEXT_ + MAGENTA_;
constexpr int style::text_colour::CYAN				= TEXT_ + CYAN_;
constexpr int style::text_colour::WHITE				= TEXT_ + WHITE_;
constexpr int style::text_colour::BRIGHT_BLACK		= TEXT_ + BRIGHT_ + BLACK_;
constexpr int style::text_colour::BRIGHT_RED		= TEXT_ + BRIGHT_ + RED_;
constexpr int style::text_colour::BRIGHT_GREEN		= TEXT_ + BRIGHT_ + GREEN_;
constexpr int style::text_colour::BRIGHT_YELLOW		= TEXT_ + BRIGHT_ + YELLOW_;
constexpr int style::text_colour::BRIGHT_BLUE		= TEXT_ + BRIGHT_ + BLUE_;
constexpr int style::text_colour::BRIGHT_MAGENTA	= TEXT_ + BRIGHT_ + MAGENTA_;
constexpr int style::text_colour::BRIGHT_CYAN		= TEXT_ + BRIGHT_ + CYAN_;
constexpr int style::text_colour::BRIGHT_WHITE		= TEXT_ + BRIGHT_ + WHITE_;
constexpr int style::text_colour::DEFAULT			= TEXT_ + DEFAULT_;
int style::get_text_colour_code(EColour text_colour)
{
	switch (text_colour)
	{
	case EColour::BLACK:			return text_colour::BLACK;
	case EColour::RED:				return text_colour::RED;
	case EColour::GREEN:			return text_colour::GREEN;
	case EColour::YELLOW:			return text_colour::YELLOW;
	case EColour::BLUE:				return text_colour::BLUE;
	case EColour::MAGENTA:			return text_colour::MAGENTA;
	case EColour::CYAN:				return text_colour::CYAN;
	case EColour::WHITE:			return text_colour::BRIGHT_WHITE;
	case EColour::BRIGHT_BLACK:		return text_colour::BRIGHT_BLACK;
	case EColour::BRIGHT_RED:		return text_colour::BRIGHT_RED;
	case EColour::BRIGHT_GREEN:		return text_colour::BRIGHT_GREEN;
	case EColour::BRIGHT_YELLOW:	return text_colour::BRIGHT_YELLOW;
	case EColour::BRIGHT_BLUE:		return text_colour::BRIGHT_BLUE;
	case EColour::BRIGHT_MAGENTA:	return text_colour::BRIGHT_MAGENTA;
	case EColour::BRIGHT_CYAN:		return text_colour::BRIGHT_CYAN;
	case EColour::BRIGHT_WHITE:		return text_colour::BRIGHT_WHITE;
	default:						return text_colour::DEFAULT;
	}
}

constexpr int style::back_colour::BLACK				= BACK_ + BLACK_;
constexpr int style::back_colour::RED				= BACK_ + RED_;
constexpr int style::back_colour::GREEN				= BACK_ + GREEN_;
constexpr int style::back_colour::YELLOW			= BACK_ + YELLOW_;
constexpr int style::back_colour::BLUE				= BACK_ + BLUE_;
constexpr int style::back_colour::MAGENTA			= BACK_ + MAGENTA_;
constexpr int style::back_colour::CYAN				= BACK_ + CYAN_;
constexpr int style::back_colour::WHITE				= BACK_ + WHITE_;
constexpr int style::back_colour::BRIGHT_BLACK		= BACK_ + BRIGHT_ + BLACK_;
constexpr int style::back_colour::BRIGHT_RED		= BACK_ + BRIGHT_ + RED_;
constexpr int style::back_colour::BRIGHT_GREEN		= BACK_ + BRIGHT_ + GREEN_;
constexpr int style::back_colour::BRIGHT_YELLOW		= BACK_ + BRIGHT_ + YELLOW_;
constexpr int style::back_colour::BRIGHT_BLUE		= BACK_ + BRIGHT_ + BLUE_;
constexpr int style::back_colour::BRIGHT_MAGENTA	= BACK_ + BRIGHT_ + MAGENTA_;
constexpr int style::back_colour::BRIGHT_CYAN		= BACK_ + BRIGHT_ + CYAN_;
constexpr int style::back_colour::BRIGHT_WHITE		= BACK_ + BRIGHT_ + WHITE_;
constexpr int style::back_colour::DEFAULT			= BACK_ + DEFAULT_;
int style::get_back_colour_code(EColour back_colour)
{
	switch (back_colour)
	{
	case EColour::BLACK:			return back_colour::BLACK;
	case EColour::RED:				return back_colour::RED;
	case EColour::GREEN:			return back_colour::GREEN;
	case EColour::YELLOW:			return back_colour::YELLOW;
	case EColour::BLUE:				return back_colour::BLUE;
	case EColour::MAGENTA:			return back_colour::MAGENTA;
	case EColour::CYAN:				return back_colour::CYAN;
	case EColour::WHITE:			return back_colour::BRIGHT_WHITE;
	case EColour::BRIGHT_BLACK:		return back_colour::BRIGHT_BLACK;
	case EColour::BRIGHT_RED:		return back_colour::BRIGHT_RED;
	case EColour::BRIGHT_GREEN:		return back_colour::BRIGHT_GREEN;
	case EColour::BRIGHT_YELLOW:	return back_colour::BRIGHT_YELLOW;
	case EColour::BRIGHT_BLUE:		return back_colour::BRIGHT_BLUE;
	case EColour::BRIGHT_MAGENTA:	return back_colour::BRIGHT_MAGENTA;
	case EColour::BRIGHT_CYAN:		return back_colour::BRIGHT_CYAN;
	case EColour::BRIGHT_WHITE:		return back_colour::BRIGHT_WHITE;
	default:						return back_colour::DEFAULT;
	}
}

constexpr int style::RESET = 0;
constexpr int style::BOLD = 1;
constexpr int style::BOLD_OFF = 22;
constexpr int style::ITALIC = 3;
constexpr int style::ITALIC_OFF = 23;
constexpr int style::UNDERLINE_SINGLE = 4;
constexpr int style::UNDERLINE_DOUBLE = 4;
constexpr int style::UNDERLINE_OFF = 24;
constexpr int style::BLINKING_SLOW = 5;
constexpr int style::BLINKING_RAPID = 6;
constexpr int style::BLINKING_OFF = 25;
constexpr int style::REVERSE_COLOURS = 7;
constexpr int style::REVERSE_COLOURS_OFF = 27;
constexpr int style::CROSS_OUT = 9;
constexpr int style::CROSS_OUT_OFF = 29;

int style::get_blinking_code(EBlinking blinking)
{
	switch (blinking)
	{
	case EBlinking::SLOW:	return BLINKING_SLOW;
	case EBlinking::RAPID:	return BLINKING_RAPID;
	default:				return BLINKING_OFF;
	}
}

int style::get_underline_code(EUnderline underline)
{
	switch (underline)
	{
	case EUnderline::SINGLE:	return UNDERLINE_SINGLE;
	case EUnderline::DOUBLE:	return UNDERLINE_DOUBLE;
	default:					return UNDERLINE_OFF;
	}
}
