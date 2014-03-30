//  Created by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (sdexh, or PickelBarelKumqueat),
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows


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