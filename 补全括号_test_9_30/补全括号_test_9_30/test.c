#include "SList.h"

void CompletionBrackets(char* str);

int main()
{
	char str[] = "1+2)*3-4)*5-6)))";


	return 0;
}

void CompletionBrackets(char* str)
{
	SLTNode* plist = NULL;

	while (*str)
	{

		SListPushBack(&plist, *str);
		str++;

	}




}