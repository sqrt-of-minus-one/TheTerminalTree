////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Tree.h                      //
////////////////////////////////////////

#include "Tree.h"

#include "Data.h"

#include <functional>

using namespace the_tree;
using namespace std::chrono_literals;

Tree::Tree(int age) :
	age_(age)
{}

Tree::~Tree()
{
	stop_drawing();
}

void Tree::draw_once(std::ostream& out, int position)
{
	out << ui::Escape::RESTORE_CURSOR_POSITION << TREES.at(age_)[position];
}

void Tree::start_drawing(std::ostream& out)
{
	stop_drawing();
	drawing_ = true;
	draw_thread_ = std::make_unique<std::thread>(&Tree::draw_loop_, this, std::ref(out));
}

void Tree::stop_drawing()
{
	drawing_ = false;
	if (draw_thread_)
	{
		draw_thread_->join();
		draw_thread_.reset();
	}
}

void Tree::draw_loop_(std::ostream& out)
{
	int position = 0;
	const std::vector<ui::FormattedString>& FRAMES = TREES.at(age_);
	out << ui::Escape::SAVE_CURSOR_POSITION;
	while (drawing_)
	{
		draw_once(out, position);
		if (++position >= FRAMES.size())
		{
			position = 0;
		}
		std::this_thread::sleep_for(1.s);
	}
}
