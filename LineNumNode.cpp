#include "LineNumNode.h"


LineNumNode::LineNumNode(int num)
{
	number = num;
	next = NULL;
}
	
//accessors
int LineNumNode::get_number()					{return number;}
LineNumNode *LineNumNode::get_next()			{return next;}

//mutator
void LineNumNode::set_num(int num)				{number = num;}
void LineNumNode::set_next(LineNumNode *nxt)	{next = nxt;}
