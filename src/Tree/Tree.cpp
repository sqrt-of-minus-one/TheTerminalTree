////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Tree.h                      //
////////////////////////////////////////

#include "Tree.h"

#include "Data.h"

#include <chrono>
#include <functional>
#include <iomanip>

using namespace the_tree;
using namespace std::chrono_literals;
namespace chr = std::chrono;
using Clock = chr::system_clock;

constexpr auto DRAW_FREQ = 1.s;

Tree::Tree() :
	fixed_age_(false)
{}

Tree::Tree(int age) :
	age_(age),
	fixed_age_(true)
{}

Tree::~Tree()
{
	stop_drawing();
}

void Tree::draw_once(std::ostream& out, int position)
{
	// Get the current date
	Clock::time_point time = Clock::now();
	std::time_t c_time = Clock::to_time_t(time);
	std::tm* ymd = std::localtime(&c_time);

	if (!fixed_age_)
	{
		set_age_(*ymd);
	}

	// Print the date and the Tree
	out << ui::Escape::RESTORE_CURSOR_POSITION << std::setfill('0') << std::right <<
		std::setw(2) << ymd->tm_mday << '.' << std::setw(2) << ymd->tm_mon + 1 << '.' << std::setw(4) << ymd->tm_year + 1900 << ' ' <<
			std::setw(2) << ymd->tm_hour << ':' << std::setw(2) << ymd->tm_min << ':' << std::setw(2) << ymd->tm_sec << std::endl <<
		at_or_first(TREES, age_)[position];
}

void Tree::start_drawing(std::ostream& out)
{
	stop_drawing(); // If the Tree is already being drawn, stop it
	drawing_ = true;
	draw_thread_ = std::make_unique<std::thread>(&Tree::draw_loop_, this, std::ref(out));
}

void Tree::stop_drawing()
{
	drawing_ = false;
	if (draw_thread_) // If the Tree is being drawn, wait until it stops
	{
		draw_thread_->join();
		draw_thread_.reset();
	}
}

void Tree::set_age_(const std::tm& ymd)
{
	int age = 0;
	switch (ymd.tm_mon)
	{
	case 11: // December
	{
		switch (ymd.tm_mday)
		{
		case 26:
		case 27:
			age = 1;
			break;
		case 28:
		case 29:
			age = 2;
			break;
		case 30:
		case 31:
			age = 3;
			break;
		}
		break;
	}
	case 0: // January
	{
		if (ymd.tm_mday <= 21)
		{
			age = 4;
		}
		break;
	}
	}
	age_ = age;
}

void Tree::draw_loop_(std::ostream& out)
{
	int position = 0;
	out << ui::Escape::SAVE_CURSOR_POSITION;
	while (drawing_)
	{
		draw_once(out, position);
		if (++position >= at_or_first(TREES, age_).size()) // Next position
		{
			position = 0;
		}
		std::this_thread::sleep_for(DRAW_FREQ);
	}
}
