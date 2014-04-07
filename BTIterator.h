//  Created by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (sdexh, or PickelBarelKumqueat),
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows

#ifndef BTIterator_h
#define BTIterator_h

#include "common.h"
#include "BinaryTreeNode.h"

class BTIterator
{
private:
	BinaryTreeNode *find_parent(BinaryTreeNode *root, char *target);
	BinaryTreeNode *examin_children(BinaryTreeNode *root, char *target);
	BinaryTreeNode *find_next(BinaryTreeNode *root, char *target);
	BinaryTreeNode *get_leftmost(BinaryTreeNode *root);

public:
    void add(BinaryTreeNode** head, const char *name, int line_num);
	void clear(BinaryTreeNode *n);
	BinaryTreeNode *get_next(BinaryTreeNode *head, BinaryTreeNode *last);
	BinaryTreeNode *find(BinaryTreeNode *head, const char *name);
};

#endif
