//  Created by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (sdexh, or PickelBarelKumqueat),
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows


#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(char *nm)
{
	strcpy(name, nm);
	lines = NULL;
	left = NULL;
	right = NULL;
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

//mutators
void BinaryTreeNode::set_name(char *nm)					{strcpy(name, nm);}
void BinaryTreeNode::set_left(BinaryTreeNode *lft)		{left =lft;}
void BinaryTreeNode::set_right(BinaryTreeNode *rght)	{right = rght;}
void BinaryTreeNode::add_line(LineNumNode *line)
{
	if(!lines)
	{
		lines = line;
	}
	else
	{
		LineNumNode *p = lines;
		while(p)
		{
			p = p->get_next();
		}
		p->set_next(line);
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