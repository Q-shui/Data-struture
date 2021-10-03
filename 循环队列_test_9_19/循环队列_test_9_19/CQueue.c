#include "CQueue.h"

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    assert(obj);

    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    assert(obj);

    return ((obj->rear + 1) % (obj->k + 1)) == obj->front;
}


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    q->a = (int*)malloc(sizeof(int) * (k + 1));
    q->front = q->rear = 0;
    q->k = k;

    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    assert(obj);

    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->rear] = value;
    obj->rear++;

    obj->rear %= (obj->k + 1);

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;

    obj->front %= (obj->k + 1);

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return -1;
    int prevrear = obj->rear - 1;
    if (obj->rear == 0)
        prevrear = obj->k;
    return obj->a[prevrear];
}


void myCircularQueueFree(MyCircularQueue* obj)
{
    assert(obj);

    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/