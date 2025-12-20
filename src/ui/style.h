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
constexpr EColour string_to_colour(const std::string_view& str) noexcept;

// Blinking types
enum class EBlinking
{
	OFF, SLOW, RAPID
};
constexpr EBlinking string_to_blinking(const std::string_view& str) noexcept;

// Underlining types
enum class EUnderline
{
	OFF, SINGLE, DOUBLE
};
constexpr EUnderline string_to_underline(const std::string_view& str) noexcept;

namespace style
{

namespace impl_
{
	constexpr int BLACK_   = 0;
	constexpr int RED_     = 1;
	constexpr int GREEN_   = 2;
	constexpr int YELLOW_  = 3;
	constexpr int BLUE_    = 4;
	constexpr int MAGENTA_ = 5;
	constexpr int CYAN_    = 6;
	constexpr int WHITE_   = 7;
	constexpr int DEFAULT_ = 9;
	constexpr int TEXT_    = 30;
	constexpr int BACK_    = 40;
	constexpr int BRIGHT_  = 60;
}

// Codes of the colours of text
namespace text_colour
{
	constexpr int BLACK          = impl_::TEXT_ + impl_::BLACK_;
	constexpr int RED            = impl_::TEXT_ + impl_::RED_;
	constexpr int GREEN          = impl_::TEXT_ + impl_::GREEN_;
	constexpr int YELLOW         = impl_::TEXT_ + impl_::YELLOW_;
	constexpr int BLUE           = impl_::TEXT_ + impl_::BLUE_;
	constexpr int MAGENTA        = impl_::TEXT_ + impl_::MAGENTA_;
	constexpr int CYAN           = impl_::TEXT_ + impl_::CYAN_;
	constexpr int WHITE          = impl_::TEXT_ + impl_::WHITE_;
	constexpr int BRIGHT_BLACK   = impl_::TEXT_ + impl_::BRIGHT_ + impl_::BLACK_;
	constexpr int BRIGHT_RED     = impl_::TEXT_ + impl_::BRIGHT_ + impl_::RED_;
	constexpr int BRIGHT_GREEN   = impl_::TEXT_ + impl_::BRIGHT_ + impl_::GREEN_;
	constexpr int BRIGHT_YELLOW  = impl_::TEXT_ + impl_::BRIGHT_ + impl_::YELLOW_;
	constexpr int BRIGHT_BLUE    = impl_::TEXT_ + impl_::BRIGHT_ + impl_::BLUE_;
	constexpr int BRIGHT_MAGENTA = impl_::TEXT_ + impl_::BRIGHT_ + impl_::MAGENTA_;
	constexpr int BRIGHT_CYAN    = impl_::TEXT_ + impl_::BRIGHT_ + impl_::CYAN_;
	constexpr int BRIGHT_WHITE   = impl_::TEXT_ + impl_::BRIGHT_ + impl_::WHITE_;
	constexpr int DEFAULT        = impl_::TEXT_ + impl_::DEFAULT_;
}
constexpr int get_text_colour_code(EColour text_colour) noexcept;

// Codes of the colours of background
namespace back_colour
{
	constexpr int BLACK          = impl_::BACK_ + impl_::BLACK_;
	constexpr int RED            = impl_::BACK_ + impl_::RED_;
	constexpr int GREEN          = impl_::BACK_ + impl_::GREEN_;
	constexpr int YELLOW         = impl_::BACK_ + impl_::YELLOW_;
	constexpr int BLUE           = impl_::BACK_ + impl_::BLUE_;
	constexpr int MAGENTA        = impl_::BACK_ + impl_::MAGENTA_;
	constexpr int CYAN           = impl_::BACK_ + impl_::CYAN_;
	constexpr int WHITE          = impl_::BACK_ + impl_::WHITE_;
	constexpr int BRIGHT_BLACK   = impl_::BACK_ + impl_::BRIGHT_ + impl_::BLACK_;
	constexpr int BRIGHT_RED     = impl_::BACK_ + impl_::BRIGHT_ + impl_::RED_;
	constexpr int BRIGHT_GREEN   = impl_::BACK_ + impl_::BRIGHT_ + impl_::GREEN_;
	constexpr int BRIGHT_YELLOW  = impl_::BACK_ + impl_::BRIGHT_ + impl_::YELLOW_;
	constexpr int BRIGHT_BLUE    = impl_::BACK_ + impl_::BRIGHT_ + impl_::BLUE_;
	constexpr int BRIGHT_MAGENTA = impl_::BACK_ + impl_::BRIGHT_ + impl_::MAGENTA_;
	constexpr int BRIGHT_CYAN    = impl_::BACK_ + impl_::BRIGHT_ + impl_::CYAN_;
	constexpr int BRIGHT_WHITE   = impl_::BACK_ + impl_::BRIGHT_ + impl_::WHITE_;
	constexpr int DEFAULT        = impl_::BACK_ + impl_::DEFAULT_;
}
constexpr int get_back_colour_code(EColour back_colour) noexcept;

// Codes of other styles
constexpr int RESET               = 0;
constexpr int BOLD                = 1;
constexpr int BOLD_OFF            = 22;
constexpr int ITALIC              = 3;
constexpr int ITALIC_OFF          = 23;
constexpr int UNDERLINE_SINGLE    = 4;
constexpr int UNDERLINE_DOUBLE    = 4;
constexpr int UNDERLINE_OFF       = 24;
constexpr int BLINKING_SLOW       = 5;
constexpr int BLINKING_RAPID      = 6;
constexpr int BLINKING_OFF        = 25;
constexpr int REVERSE_COLOURS     = 7;
constexpr int REVERSE_COLOURS_OFF = 27;
constexpr int CROSS_OUT           = 9;
constexpr int CROSS_OUT_OFF       = 29;

constexpr int get_blinking_code(EBlinking blinking) noexcept;
constexpr int get_underline_code(EUnderline underline) noexcept;

}

}

#include "style.tpp"
