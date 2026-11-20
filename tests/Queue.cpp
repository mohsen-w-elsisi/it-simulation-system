#include <cassert>

#include "PriorityQueue.h"
#include "Queue.h"

int main()
{
    Queue<int> queue;
    int value = 0;

    assert(queue.isEmpty());
    assert(queue.getCount() == 0);
    assert(!queue.dequeue(value));
    assert(!queue.peek(value));

    assert(queue.enqueue(10));
    assert(queue.enqueue(20));
    assert(queue.enqueue(30));
    assert(queue.getCount() == 3);

    assert(queue.peek(value));
    assert(value == 10);

    assert(queue.getAt(0, value));
    assert(value == 10);
    assert(queue.getAt(1, value));
    assert(value == 20);
    assert(queue.getAt(2, value));
    assert(value == 30);
    assert(!queue.getAt(3, value));
    assert(!queue.getAt(-1, value));

    assert(queue.remove(20));
    assert(queue.getCount() == 2);
    assert(queue.dequeue(value));
    assert(value == 10);
    assert(queue.dequeue(value));
    assert(value == 30);
    assert(queue.isEmpty());
    assert(!queue.dequeue(value));

    PriorityQueue<int> priorityQueue;
    assert(priorityQueue.isEmpty());

    priorityQueue.enqueue(10, 1);
    priorityQueue.enqueue(30, 3);
    priorityQueue.enqueue(20, 2);

    assert(priorityQueue.getCount() == 3);
    assert(priorityQueue.peek(value));
    assert(value == 30);

    assert(priorityQueue.dequeue(value));
    assert(value == 30);
    assert(priorityQueue.dequeue(value));
    assert(value == 20);
    assert(priorityQueue.dequeue(value));
    assert(value == 10);
    assert(priorityQueue.isEmpty());
}
