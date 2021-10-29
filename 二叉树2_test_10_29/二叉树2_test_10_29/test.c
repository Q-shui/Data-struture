#include "BinaryTree.h"

int main()
{
	char str[] = "ABD##E#H##CF##G##";

	int i = 0;
	int length = sizeof(str) / sizeof(str[0]);

	BTNode* root = BinaryTreeCreate(str, length, &i);

	printf("BinaryTreeSize = %d\n", BinaryTreeSize(root));
	printf("BinaryTreeLevelKSize = %d\n", BinaryTreeLevelKSize(root, 3));

	BTNode* find = BinaryTreeFind(root, 'A');
	printf("%c\n", find->_data);

	BinaryTreePrevOrder(root);
	printf("\n");

	BinaryTreeInOrder(root);
	printf("\n");

	BinaryTreePostOrder(root);
	printf("\n");

	//BinaryTreeLevelOrder(root);
	//printf("\n");

	//printf("%d\n", BinaryTreeComplete(root);

	return 0;
}
