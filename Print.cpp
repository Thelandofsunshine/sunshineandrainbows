//
//  Print.cpp
//  Lab4
//
//  Created by Bryce Holton.
//
//  Updated by:
//	Ashley Krueger (alkruege), Mathew Scott Dexheimer (PickelBarelKumqueat), 
//	Savannah Pucket (snpuckett), Emily Falkner(emfalkne, or emilymarie)
//	GitHub Url: https://github.com/Thelandofsunshine/sunshineandrainbows


#include "Print.h"

static int lc;

const char* const SYMBOL_STRINGS[] =
{
    "<no token>", "<IDENTIFIER>", "<NUMBER>", "<STRING>",
    "^","*","(",")","-","+","=","[","]",":",";",
    "<",">",",",".","/",":=","<=",">=","<>","..",
    "<END OF FILE>", "<ERROR>",
    "AND","ARRAY","BEGIN","CASE","CONST","DIV","DO","DOWNTO",
    "ELSE","END","FILE","FOR","FUNCTION","GOTO","IF","IN",
    "LABEL","MOD","NIL","NOT","OF","OR","PACKED","PROCEDURE",
    "PROGRAM","RECORD","REPEAT","SET","THEN","TO","TYPE","UNTIL",
    "VAR","WHILE","WITH",
};

Print::Print(char source_name[], char date[])
{
    this->sourceFileName = string(source_name);
    this->currentDate = string(date);
    this->pageNumber = 0;
	lc = 0;
	head = NULL;
}
Print::~Print()
{
    
}
void Print::printLine(char line[])
{
    char save_ch = '\0';
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        printPageHeader();
        line_count = 1;
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH)
    {
        save_chp = &line[MAX_PRINT_LINE_LENGTH];
    }
    if (save_chp)
    {
        save_ch = *save_chp;
        *save_chp = '\0';
    }
    printf("%s", line);
    if (save_chp)
    {
        *save_chp = save_ch;
    }
	lc++;
}
void Print::printPageHeader()
{
    putchar(FORM_FEED_CHAR);
    printf("Page    %d  %s  %s\n\n", ++pageNumber, sourceFileName.c_str(), currentDate.c_str());
}
void Print::printToken(Token *token)
{
    char line[MAX_SOURCE_LINE_LENGTH + 32];
    const char *symbol_string = SYMBOL_STRINGS[token->getCode()];
    switch (token->getCode())
    {
        case NUMBER:
            if (token->getType() == INTEGER_LIT)
            {
                sprintf(line, "    >> %-16s %d (integer)\n", symbol_string, token->getIntLiteral());
            }
            else
            {
                sprintf(line, "    >> %-16s %g (real)\n", symbol_string, token->getRealLiteral());
            }
            break;
        case STRING:
            sprintf(line, "    >> %-16s %-s\n", symbol_string, token->getStringLiteral().c_str());
            break;
        default:
            sprintf(line, "    >> %-16s %-s\n", symbol_string, token->getTokenString().c_str());
            break;
    }
    printLine(line);
	lc--;
	//adds the identifiers to the tree
	if(token->getCode() == IDENTIFIER)
	{
		BTIterator bti;
		//tries to find the identifier
		BinaryTreeNode *p = bti.find(head, token->getTokenString().data());
		if(p)
		{
			p->add_line(lc);
		}
		else
		{
			bti.add(&head, token->getTokenString().data(), lc);
		}
	}
}

void Print::printBT()
{
    BinaryTreeNode* current = NULL;
    BTIterator bti;
	
    current=bti.get_next(head,current);
    
    printf("Cross Reference Information\n");
    printf("Identifier\tLineNumbers\n");
    printf("------------\t-----------\n");

    
    while (current!=NULL)
    {
        
        printf(current->get_name());
        printf("\t");
        LineNumNode *num=current->get_lines();
        printf("\t%d", num->get_number());
        while(num->get_next()!=NULL)
        {
            num = num->get_next();
            printf("\t%d", num->get_number());
        }
        printf("\n");
        current=bti.get_next(head,current);
        
    }
}
