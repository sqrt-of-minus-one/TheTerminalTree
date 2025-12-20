////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: style.tpp                   //
////////////////////////////////////////

namespace ui
{

constexpr EColour string_to_colour(const std::string_view& str) noexcept
{
	     if (str == "black")          return EColour::BLACK;
	else if (str == "red")            return EColour::RED;
	else if (str == "green")          return EColour::GREEN;
	else if (str == "yellow")         return EColour::YELLOW;
	else if (str == "blue")           return EColour::BLUE;
	else if (str == "magenta")        return EColour::MAGENTA;
	else if (str == "cyan")           return EColour::CYAN;
	else if (str == "white")          return EColour::WHITE;
	else if (str == "bright_black")   return EColour::BRIGHT_BLACK;
	else if (str == "bright_red")     return EColour::BRIGHT_RED;
	else if (str == "bright_green")   return EColour::BRIGHT_GREEN;
	else if (str == "bright_yellow")  return EColour::BRIGHT_YELLOW;
	else if (str == "bright_blue")    return EColour::BRIGHT_BLUE;
	else if (str == "bright_magenta") return EColour::BRIGHT_MAGENTA;
	else if (str == "bright_cyan")    return EColour::BRIGHT_CYAN;
	else if (str == "bright_white")   return EColour::BRIGHT_WHITE;
	else                              return EColour::DEFAULT;
}

constexpr EBlinking string_to_blinking(const std::string_view& str) noexcept
{
	     if (str == "slow")  return EBlinking::SLOW;
	else if (str == "rapid") return EBlinking::RAPID;
	else                     return EBlinking::OFF;
}

constexpr EUnderline string_to_underline(const std::string_view& str) noexcept
{
	     if (str == "single") return EUnderline::SINGLE;
	else if (str == "double") return EUnderline::DOUBLE;
	else                      return EUnderline::OFF;
}

constexpr int style::get_text_colour_code(EColour text_colour) noexcept
{
	switch (text_colour)
	{
	case EColour::BLACK:          return text_colour::BLACK;
	case EColour::RED:            return text_colour::RED;
	case EColour::GREEN:          return text_colour::GREEN;
	case EColour::YELLOW:         return text_colour::YELLOW;
	case EColour::BLUE:           return text_colour::BLUE;
	case EColour::MAGENTA:        return text_colour::MAGENTA;
	case EColour::CYAN:           return text_colour::CYAN;
	case EColour::WHITE:          return text_colour::BRIGHT_WHITE;
	case EColour::BRIGHT_BLACK:   return text_colour::BRIGHT_BLACK;
	case EColour::BRIGHT_RED:     return text_colour::BRIGHT_RED;
	case EColour::BRIGHT_GREEN:   return text_colour::BRIGHT_GREEN;
	case EColour::BRIGHT_YELLOW:  return text_colour::BRIGHT_YELLOW;
	case EColour::BRIGHT_BLUE:    return text_colour::BRIGHT_BLUE;
	case EColour::BRIGHT_MAGENTA: return text_colour::BRIGHT_MAGENTA;
	case EColour::BRIGHT_CYAN:    return text_colour::BRIGHT_CYAN;
	case EColour::BRIGHT_WHITE:   return text_colour::BRIGHT_WHITE;
	default:                      return text_colour::DEFAULT;
	}
}

constexpr int style::get_back_colour_code(EColour back_colour) noexcept
{
	switch (back_colour)
	{
	case EColour::BLACK:          return back_colour::BLACK;
	case EColour::RED:            return back_colour::RED;
	case EColour::GREEN:          return back_colour::GREEN;
	case EColour::YELLOW:         return back_colour::YELLOW;
	case EColour::BLUE:           return back_colour::BLUE;
	case EColour::MAGENTA:        return back_colour::MAGENTA;
	case EColour::CYAN:           return back_colour::CYAN;
	case EColour::WHITE:          return back_colour::BRIGHT_WHITE;
	case EColour::BRIGHT_BLACK:   return back_colour::BRIGHT_BLACK;
	case EColour::BRIGHT_RED:     return back_colour::BRIGHT_RED;
	case EColour::BRIGHT_GREEN:   return back_colour::BRIGHT_GREEN;
	case EColour::BRIGHT_YELLOW:  return back_colour::BRIGHT_YELLOW;
	case EColour::BRIGHT_BLUE:    return back_colour::BRIGHT_BLUE;
	case EColour::BRIGHT_MAGENTA: return back_colour::BRIGHT_MAGENTA;
	case EColour::BRIGHT_CYAN:    return back_colour::BRIGHT_CYAN;
	case EColour::BRIGHT_WHITE:   return back_colour::BRIGHT_WHITE;
	default:                      return back_colour::DEFAULT;
	}
}

constexpr int style::get_blinking_code(EBlinking blinking) noexcept
{
	switch (blinking)
	{
	case EBlinking::SLOW:  return BLINKING_SLOW;
	case EBlinking::RAPID: return BLINKING_RAPID;
	default:               return BLINKING_OFF;
	}
}

constexpr int style::get_underline_code(EUnderline underline) noexcept
{
	switch (underline)
	{
	case EUnderline::SINGLE: return UNDERLINE_SINGLE;
	case EUnderline::DOUBLE: return UNDERLINE_DOUBLE;
	default:                 return UNDERLINE_OFF;
	}
}


}
