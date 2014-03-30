//  Created by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (sdexh, or PickelBarelKumqueat),
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows


#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h

#include "common.h"
#include "LineNumNode.h"

class BinaryTreeNode
{
private:
	char name[10];
	LineNumNode *lines;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	void rem_lnn(LineNumNode *n);

public:
	BinaryTreeNode(char *nm);
	~BinaryTreeNode();
	
	//accessors
	char *get_name();
	LineNumNode *get_lines();
	BinaryTreeNode *get_left();
	BinaryTreeNode *get_right();

	//mutators
	void set_name(char *nm);
	void add_line(LineNumNode *line);
	void set_left(BinaryTreeNode *left);
	void set_right(BinaryTreeNode *right);

};

#endif