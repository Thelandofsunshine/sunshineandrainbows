//
//  Print.h
//  Lab4
//
//  Created by Bryce Holton.
//
//  Updated by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (PickelBarelKumqueat), 
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows


#ifndef __Lab4__Print__
#define __Lab4__Print__

#include <iostream>
#include "common.h"
#include "Token.h"

using namespace std;

class Print
{
private:
    string sourceFileName;
    string currentDate;
    int pageNumber;
    
    void printPageHeader();
    
public:
    Print(char source_name[], char date[]);
    ~Print();
    
    void printLine(char line[]);
    void printToken(Token *token);
};

#endif /* defined(__Lab4__Print__) */
