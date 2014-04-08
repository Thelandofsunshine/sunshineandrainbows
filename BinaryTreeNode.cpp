//  Created by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (sdexh, or PickelBarelKumqueat),
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows


#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

BinaryTreeNode::BinaryTreeNode(char *nm)
{
	strcpy(name, nm);
	lines = NULL;
	left = NULL;
	right = NULL;
	traversed = false;
}

BinaryTreeNode::BinaryTreeNode(char *nm, int ln)
{
	strcpy(name, nm);
	lines = NULL;
	add_line(ln);
	left = NULL;
	right = NULL;
	traversed = false;
}

BinaryTreeNode::~BinaryTreeNode()
{
	rem_lnn(lines);
}
	
//accessors
char *BinaryTreeNode::get_name()						{return name;}
LineNumNode *BinaryTreeNode::get_lines()				{return lines;}
BinaryTreeNode *BinaryTreeNode::get_left()				{return left;}
BinaryTreeNode *BinaryTreeNode::get_right()				{return right;}
bool BinaryTreeNode::get_traversed()					{return traversed;}

//mutators
void BinaryTreeNode::set_name(char *nm)					{strcpy(name, nm);}
void BinaryTreeNode::set_left(BinaryTreeNode *lft)		{left =lft;}
void BinaryTreeNode::set_right(BinaryTreeNode *rght)	{right = rght;}
void BinaryTreeNode::set_traversed(bool t)				{traversed = t;}
void BinaryTreeNode::add_line(int num)
{
	if(!lines)
	{
		lines = new LineNumNode(num);
	}
	else
	{
		LineNumNode *p = lines;
		while(p->get_next())
		{
			p = p->get_next();
		}
		p->set_next(new LineNumNode(num));
	}
}

//recursively removes the object's line list
void BinaryTreeNode::rem_lnn(LineNumNode *n)
{
	if(n)
	{
		rem_lnn(n->get_next());
		delete n;
	}
}