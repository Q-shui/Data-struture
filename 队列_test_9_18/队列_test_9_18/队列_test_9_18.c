#include "Queue.h"

int main(void)
{
	Queue qt;

	QueueInit(&qt);

	QueuePush(&qt, 1);
	QueuePush(&qt, 2);
	QueuePush(&qt, 3);

	QueuePop(&qt);

	printf("%d\n", QueueFront(&qt));
	printf("%d\n", QueueBack(&qt));

	printf("%d\n", QueueSize(&qt));

	printf("%d\n", QueueEmpty(&qt));

	QueueDestroy(&qt);

	return 0;
}