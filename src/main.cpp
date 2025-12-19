////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: main.cpp                    //
////////////////////////////////////////

//////////*\\\\\\\\\\|#############################################################################
////////// \\\\\\\\\\|##### ____########  ###  ###  ____####  ##############  ####  ###############
/////////_*_\\\\\\\\\|####  ############  ###  ###  ########  ##############__####__###############
/////////o .\\\\\\\\\|####  ############  ___  ###  ########__#####################################
////////.  0 \\\\\\\\|####_ ############  ###  ###  #######################__ #### __##############
///////_______\\\\\\\|#####_____########__###__###__########__###############______##########2026##
/////////| |\\\\\\\\\|#############################################################################

#include "Tree/Tree.h"

#include "ui/ui.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

using namespace ui_literals;
using namespace std::chrono_literals;

// Very secret password, do not look!
const std::string SECRET_PASSWORD = "Happi_Neu_Jear";

void print_usage(const char* name)
{
	std::cout << std::left <<
		"Usage: " << name << " [options]" << std::endl <<
		" Options:" << std::endl <<
		" " << std::setw(20) << "-h / --help: " << "Print usage and exit." << std::endl <<
		" " << std::setw(20) << "-v / --version: " << "Print version and exit." << std::endl <<
		" " << std::setw(20) << "-a [age] [password]" << "Draw a tree with the specified age (a secret password is required)" << std::endl;
}

void print_version()
{
	std::cout <<
		"The Terminal Tree" << std::endl <<
		"\tby sqrt(-1)" << std::endl <<
		"\tv. 0.0.1" << std::endl;
}

int main(int argc, const char** argv)
{
	bool arg_h = false, arg_v = false;
	std::optional<int> arg_age;
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string arg = argv[i];
			if (arg == "-h" || arg == "--help")
			{
				arg_h = true;
			}
			else if (arg == "-v" || arg == "--version")
			{
				arg_v = true;
			}
			else if (arg == "-a")
			{
				if (i + 2 >= argc)
				{
					std::cout << "More data are expected after -a" << std::endl;
					print_usage(argv[0]);
					return 1;
				}
				std::string age = argv[++i], password = argv[++i];
				if (password != SECRET_PASSWORD)
				{
					std::cout << "Wrong password" << std::endl;
					return 1;
				}
				else
				{
					try
					{
						arg_age = std::stoi(age);
					}
					catch (std::invalid_argument _)
					{}
				}
			}
			else
			{
				std::cout << "Unknown argument: arg" << std::endl;
				print_usage(argv[0]);
				return 1;
			}
		}
		if (arg_h) print_usage(argv[0]);
		if (arg_v) print_version();
		if (arg_h || arg_v) return 0;
	}

	std::shared_ptr<the_tree::Tree> tree;
	if (arg_age)
	{
		tree = std::make_shared<the_tree::Tree>(*arg_age);
	}
	else
	{
		tree = std::make_shared<the_tree::Tree>();
	}
	tree->start_drawing();

	std::string input;
	std::getline(std::cin, input);
	tree->stop_drawing();
	return 0;
}
