//  Created by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (sdexh, or PickelBarelKumqueat),
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows

#include "BTIterator.h"

void BTIterator::add(BinaryTreeNode** head, const char *nm, int line_num)
{    
    BinaryTreeNode* current = *head;
	char name[12];
	strcpy(name, nm);
    if(!*head)
    {
        *head = new BinaryTreeNode(name, line_num);
    }
    else
    {
        while(true)
        {
            if(strcmp(current->get_name(), name) < 0)
            {
                if(NULL != current->get_left())
                {
                    current = current->get_left();
                }
                else
                {
                    current->set_left(new BinaryTreeNode(name, line_num));
                    return;
                }
            }
            else
            {
                if(NULL != current->get_right())
                {
                    current = current->get_right();
                }
                else
                {
                    current->set_right(new BinaryTreeNode(name, line_num));
                    return;
                }
            }
        }
    }
}

void BTIterator::clear(BinaryTreeNode *n)
{
    if(n)
	{
		clear(n->get_left());
		clear(n->get_right());
		delete n;
	}
}

BinaryTreeNode* BTIterator::get_next(BinaryTreeNode *head, BinaryTreeNode *last)
{
	char *pn;
	BinaryTreeNode *p = head;
	if(head == NULL)
	{
		return NULL;
	}
	if(last == NULL)
	{
		if(!p->get_left())
		{
			if(p->get_right())
			{
				p = p->get_right();
			}
			else
			{
				return p;
			}
		}
		p = get_leftmost(p);
		return p;
	}
	if(last == head)
	{
		if(p->get_right())
		{
			p = p->get_right();
		}
		else
		{
			return NULL;
		}
		p = get_leftmost(p);
		return p;
	}
	p = last;
	pn = p->get_name();
	if(!p->get_right())
	{
		p = find_parent(p, pn);
		return p;
	}
	else
	{
		p = p->get_right();
		p = get_leftmost(p);
		return p;
	}
}

BinaryTreeNode *BTIterator::find(BinaryTreeNode *head, const char *nm)
{
	BinaryTreeNode* current = head;
	char name[12];
	strcpy(name, nm);
    if(!head)
    {
        return NULL;
    }
    else
    {
        while(true)
        {
			if(strcmp(current->get_name(), name) == 0)
			{
				return current;
			}
            if(strcmp(current->get_name(), name) < 0)
            {
                if(NULL != current->get_left())
                {
                    current = current->get_left();
                }
                else
                {
                    return NULL;
                }
            }
            else
            {
                if(NULL != current->get_right())
                {
                    current = current->get_right();
                }
                else
                {
                    return NULL;
                }
            }
        }
    }

}

BinaryTreeNode *BTIterator::find_parent(BinaryTreeNode *root, char *target)
{
	BinaryTreeNode *current = examin_children(root, target);
	if(current == NULL)
	{
		return NULL;
	}
	else
	{
		current = root;
        while(!examin_children(current, target))
        {
			current = find_next(current, target);
        }
		return current;
    }

}

BinaryTreeNode *BTIterator::examin_children(BinaryTreeNode *root, char *target)
{
	if(0 == strcmp(root->get_name(), target))
	{
		return NULL;
	}
    else if(root->get_left())
	{
		if(0 == strcmp(root->get_left()->get_name(), target))
		{
			return root;
		}
	}
	else if(root->get_right())
	{
		if(0 == strcmp(root->get_right()->get_name(), target))
		{
			return root;
		}
	}
	return NULL;
}

BinaryTreeNode *BTIterator::find_next(BinaryTreeNode *root, char *target)
{
	if(strcmp(root->get_name(), target) > 0)
	{
		if(root->get_left())
		{
			return root->get_left();
		}
		return NULL;
	}
    else
	{
		if(root->get_right())
		{
			return root->get_right();
		}
		return NULL;
	}
}

BinaryTreeNode *BTIterator::get_leftmost(BinaryTreeNode *root)
{
	BinaryTreeNode *p = root;
	while(p->get_left())
	{
		p = p->get_left();
	}
	return p;
}