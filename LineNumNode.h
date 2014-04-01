#ifndef LineNumNode_h
#define LineNumNode_h

#include "common.h"

class LineNumNode
{
private:
	int number;
	LineNumNode *next;

public:
	LineNumNode(int num);
	
	//accessors
	int get_number();
	LineNumNode *get_next();

	//mutator
	void set_num(int num);
	void set_next(LineNumNode *next);

};

#endif