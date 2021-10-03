#include "CQueue.h"

void Test();

int main(void)
{
	Test();

	return 0;
}

void Test()
{
	MyCircularQueue* pst = myCircularQueueCreate(3);

	printf("%d\n", myCircularQueueEnQueue(pst, 1));
	printf("%d\n", myCircularQueueEnQueue(pst, 2));
	printf("%d\n", myCircularQueueEnQueue(pst, 3));
	printf("%d\n", myCircularQueueEnQueue(pst, 4));

	printf("%d\n", myCircularQueueRear(pst));

	printf("%d\n", myCircularQueueIsFull(pst));
	printf("%d\n", myCircularQueueDeQueue(pst));

	printf("%d\n", myCircularQueueEnQueue(pst, 4));

	printf("%d\n", myCircularQueueRear(pst));


}