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
	bool drawing_ = false;
	std::unique_ptr<std::thread> draw_thread_;

public:
	Tree(int age);
	~Tree();

	void draw_once(std::ostream& out = std::cout, int position = 0);
	void start_drawing(std::ostream& out = std::cout);
	void stop_drawing();

private:
	void draw_loop_(std::ostream& out);
};

}
