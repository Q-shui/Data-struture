#include"Stack.h"

int main(void)
{
	ST st;

	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("%d %d", StackSize(&st), StackTop(&st));

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	printf("%d %d %d", StackSize(&st), StackTop(&st), StackEmpty(&st));


	StackDestory(&st);

	return 0;
}

//bool isValid(char* s)
//{
//    ST st;
//    StackInit(&st);
//    bool match = true;
//    while (*s)
//    {
//        if ((*s == '(') || (*s == '[') || (*s == '{'))
//        {
//            StackPush(&st, *s);
//            ++s;
//        }
//        else
//        {
//            if (StackEmpty(&st))
//            {
//                match = false;
//                break;
//            }
//            char ch = StackTop(&st);
//            StackPop(&st);
//            if ((*s == ']' && ch != '[')
//                || (*s == ')' && ch != '(')
//                || (*s == '}' && ch != '{'))
//            {
//                match = false;
//                break;
//            }
//            else
//            {
//                ++s;
//
//            }
//
//        }
//
//
//
//    }
//
//    if (match == true)
//    {
//        match = StackEmpty(&st);
//    }
//
//    StackDestory(&st);
//
//    return match;
//
//}
//
//int main(void)
//{
//    char s[] = "()";
//
//    printf("%d\n", isValid(s));
//
//    return 0;
//
//
//}