////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: FormattedString.cpp         //
////////////////////////////////////////

#include "FormattedString.h"

#include <algorithm>
#include <numeric>
#include <sstream>
#include <stack>

using namespace ui;

FormattedString::FormattedString(const std::string& string) :
	pieces_()
{
	construct_(string);
}

FormattedString::FormattedString(const char* string) :
	FormattedString(std::string(string))
{}

std::list<FormattedStringPiece>& FormattedString::get_pieces()
{
	return pieces_;
}

const std::list<FormattedStringPiece>& FormattedString::get_pieces() const
{
	return pieces_;
}

bool FormattedString::is_empty() const
{
	return pieces_.empty();
}

std::string FormattedString::to_plain_string() const
{
	std::ostringstream result;
	for (const FormattedStringPiece& piece : pieces_)
	{
		result << piece.get_string();
	}
	return result.str();
}

int FormattedString::length() const
{
	int l = 0;
	for (const FormattedStringPiece& piece : pieces_)
	{
		l += piece.get_string().length();
	}
	return l;
}

void FormattedString::print_align_left(std::ostream& stream, int width, char fill) const
{
	stream << *this;
	for (int i = 0; i < width - length(); i++)
	{
		stream << fill;
	}
}

void FormattedString::print_align_right(std::ostream& stream, int width, char fill) const
{
	for (int i = 0; i < width - length(); i++)
	{
		stream << fill;
	}
	stream << *this;
}

FormattedString& FormattedString::operator=(const std::string& string)
{
	pieces_.clear();
	construct_(string);
	return *this;
}

FormattedString FormattedString::operator+(const FormattedString& string) const
{
	FormattedString result = *this;
	result += string;
	return result;
}

FormattedString FormattedString::operator+(FormattedString&& string) const
{
	FormattedString result = *this;
	result += std::forward<FormattedString>(string);
	return result;
}

FormattedString& FormattedString::operator+=(const FormattedString& string)
{
	std::list<FormattedStringPiece> new_pieces = string.get_pieces();
	if (!pieces_.empty() && !new_pieces.empty())
	{
		// The first piece of the second string was supposed to be right after the default style, but it's not anymore
		new_pieces.front().set_style(pieces_.back().get_style() - new_pieces.front().get_style());
	}
	pieces_.insert(pieces_.end(), new_pieces.begin(), new_pieces.end());
	return *this;
}

FormattedString& FormattedString::operator+=(FormattedString&& string)
{
	if (!pieces_.empty() && !string.get_pieces().empty())
	{
		// The first piece of the second string was supposed to be right after the default style, but it's not anymore
		string.get_pieces().front().set_style(pieces_.back().get_style() - string.get_pieces().front().get_style());
	}
	pieces_.splice(pieces_.end(), string.get_pieces());
	return *this;
}

std::ostream& ui::operator<<(std::ostream& stream, const FormattedString& string)
{
	TextStyle last_style;
	for (const FormattedStringPiece& piece : string.get_pieces())
	{
		stream << piece;
		last_style += piece.get_style();
	}
	// Restore the default style
	return stream << ~last_style;
}

FormattedString ui_literals::operator""_f(const char* string, size_t size)
{
	return FormattedString(string);
}

// Construction of the formatted string from the raw string
// E.g.:
//     This text contains $i(italic$), $b(bold$), and $i$t:red(more $b((much more)$)$).

enum class ECommand
{
	NOT_A_COMMAND,
	END,           // $) (end of the block)
	TEXT_COLOUR,   // $text or $t
	BACK_COLOUR,   // $background or $back
	BLINKING,      // $blinking or $blink
	BOLD,          // $bold or $b
	ITALIC,        // $italic, $i or $it
	UNDERLINE,     // $underline or $u
	CROSS_OUT      // $cross_out, $cross or $c
};

struct Command
{
	ECommand command;
	std::optional<std::string> argument;
};

ECommand recognise_command_(const std::string& string)
{
	     if (string == "t" ||
	         string == "text")       return ECommand::TEXT_COLOUR;
	else if (string == "back" ||
	         string == "background") return ECommand::BACK_COLOUR;
	else if (string == "blink" ||
	         string == "blinking")   return ECommand::BLINKING;
	else if (string == "b" ||
	         string == "bold")       return ECommand::BOLD;
	else if (string == "i" ||
	         string == "it" ||
	         string == "italic")     return ECommand::ITALIC;
	else if (string == "u" ||
	         string == "underline")  return ECommand::UNDERLINE;
	else if (string == "c" ||
	         string == "cross" ||
	         string == "cross_out")  return ECommand::CROSS_OUT;
	else                             return ECommand::NOT_A_COMMAND;
}

std::list<Command> get_commands_(const std::string& string, std::string::const_iterator& i)
{
	std::list<Command> result;
	std::string command;
	std::string argument;
	bool argument_flag = false;
	while (++i != string.cend())
	{
		switch (*i)
		{
		case '$':
		{
			result = get_commands_(string, i);
			[[fallthrough]];
		}
		case '(':
		{
			Command current_command { .command = recognise_command_(command) };
			if (current_command.command == ECommand::NOT_A_COMMAND)
			{
				current_command.argument = argument_flag ? (command + ':' + argument) : command;
			}
			else if (argument_flag)
			{
				current_command.argument = argument;
			}
			result.push_front(current_command);
			return result;
		}
		case ')':
		{
			if (!command.empty() || argument_flag)
			{
				result.push_front(Command {
					ECommand::NOT_A_COMMAND,
					argument_flag ? (command + ':' + argument + ')') : command + ')' });
				return result;
			}
			result.push_front(Command { .command = ECommand::END });
			return result;
		}
		case ':':
		{
			if (!argument_flag)
			{
				argument_flag = true;
				break;
			}
			[[fallthrough]];
		}
		case ' ':
		case '\f':
		case '\n':
		case '\r':
		case '\t':
		case '\v':
		{
			result.push_front(Command {
				ECommand::NOT_A_COMMAND,
				argument_flag ? (command + ':' + argument + *i) : command + *i });
			return result;
		}
		default:
		{
			(argument_flag ? argument : command).push_back(*i);
		}
		}
	}
	return { Command {
		ECommand::NOT_A_COMMAND,
		argument_flag ? (command + ':' + argument) : command } };
}

TextStyle get_style_from_commands_(const std::list<Command> commands)
{
	TextStyle style;
	for (const Command& command : commands)
	{
		switch (command.command)
		{
		case ECommand::TEXT_COLOUR:
		{
			style.text_colour = (command.argument ? string_to_colour(*command.argument) : EColour::DEFAULT);
			break;
		}
		case ECommand::BACK_COLOUR:
		{
			style.back_colour = (command.argument ? string_to_colour(*command.argument) : EColour::DEFAULT);
			break;
		}
		case ECommand::BLINKING:
		{
			style.blinking = (command.argument ? string_to_blinking(*command.argument) : EBlinking::SLOW);
			break;
		}
		case ECommand::BOLD:
		{
			style.bold = true;
			break;
		}
		case ECommand::ITALIC:
		{
			style.italic = true;
			break;
		}
		case ECommand::UNDERLINE:
		{
			style.underline = (command.argument ? string_to_underline(*command.argument) : EUnderline::SINGLE);
			break;
		}
		case ECommand::CROSS_OUT:
		{
			style.cross_out = true;
			break;
		}
		}
	}
	return style;
}

void FormattedString::construct_(const std::string& string)
{
	if (string.empty())
	{
		return;
	}

	// The pieces_ container is supposed to be empty
	pieces_.emplace_back();
	std::stack<TextStyle> styles;
	for (auto i = string.cbegin(); i != string.cend(); i++) // Iterate through the characters of the string
	{
		if (*i == '$') // If the dollar is found, it's the beginning of the command
		{
			auto next = i + 1;
			if (next != string.cend() && *next == '$') // If the next character is also a dollar, just put the '$' in the result string
			{
				pieces_.back().get_string().push_back('$');
				i++;
			}
			else
			{
				std::list<Command> commands = get_commands_(string, i); // Determine what commands follow the $ sign
				if (std::find_if(commands.cbegin(), commands.cend(), [&commands](const Command& command)
					{
						return (command.command == ECommand::NOT_A_COMMAND ||
								command.command == ECommand::END && commands.size() > 1);
					}) != commands.end()) // If at least one of the commands is not a command or
										// the END command is together with others (the END command can only appear alone)
				{
					// Ignore the commands and put them in the result as is
					pieces_.back().get_string().push_back('$');
					pieces_.back().get_string().insert(pieces_.back().get_string().end(), next, i + 1);
				}
				else
				{
					if (commands.front().command == ECommand::END)
					{
						// Restore the previous style from the stack
						TextStyle style;
						if (!styles.empty())
						{
							style = styles.top();
							styles.pop();
							if (!styles.empty())
							{
								style -= styles.top();
							}
							else
							{
								// The stack is empty, restore the default style
								style = ~style;
							}
						}
						pieces_.emplace_back("", style);
					}
					else
					{
						// Apply the style specified by the commands
						TextStyle style = get_style_from_commands_(commands);
						styles.push(style);
						pieces_.emplace_back("", style);
					}
				}
			}
		}
		else
		{
			// Not a '$', not a coomand. Just insert the character in the result string
			pieces_.back().get_string().push_back(*i);
		}
	}
	while (!pieces_.empty() && pieces_.back().get_string().empty()) // The empty pieces in the end are meaningless
	{
		pieces_.pop_back();
	}
	if (pieces_.size() > 1)
	{
		auto i = pieces_.begin();
		auto j = i++;
		while (i != pieces_.end())
		{
			if (j->get_string().empty()) // Empty pieces can be removed from the string
			{
				j->get_style() += i->get_style(); // "Contatenate" the styles
				j->get_string() = std::move(i->get_string());
				pieces_.erase(i++);
			}
			else
			{
				j = i++;
			}
		}
	}
}
