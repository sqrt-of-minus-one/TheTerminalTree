////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Tree.h                      //
////////////////////////////////////////

#pragma once

#include <iostream>
#include <thread>

namespace the_tree
{

class Tree
{
private:
	int age_;
	bool fixed_age_; // If false, the age will be changed according to the date
	bool drawing_ = false; // The false value is the signal for the drawing thread to stop drawing
	std::unique_ptr<std::thread> draw_thread_;

public:
	Tree(); // The age depends on the current date
	Tree(int age); // The fixed age
	~Tree();

	void draw_once(std::ostream& out = std::cout, int position = 0);
	void start_drawing(std::ostream& out = std::cout); // Creates a thread for drawing
	void stop_drawing();

private:
	void set_age_(const std::tm& ymd);
	void draw_loop_(std::ostream& out);
};

}
