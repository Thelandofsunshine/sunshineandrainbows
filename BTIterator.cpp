//
//  BTIterator.cpp
//  
//

#include "BTIterator.h"

void BTIterator::add(BinaryTreeNode** head, BinaryTreeNode* nodetoadd)
{
    if(!*head)
    {
        *head=nodetoadd;
    }
    
    BinaryTreeNode* current = head;
    
    else
    {
        while(true)
        {
            if(srtcmp(current->getName(), head)>0)
            {
                if(NULL!=current->left)
                {
                    current=current->left;
                    continue;
                }
                else
                {
                    current->left=new BinaryTreeNode(*nodetoadd);
                    return;
                }
            }
            else
            {
                if(NULL!=current->right)
                {
                    current=current->right;
                    continue;
                }
                else
                {
                    current->right=new BinaryTreeNode(*nodetoadd);
                    return;
                }
            }
        }
    }
}

void BTIterator::clear()
{
    
}

BinaryTreeNod* BTIterator::get_next()
{
    
}