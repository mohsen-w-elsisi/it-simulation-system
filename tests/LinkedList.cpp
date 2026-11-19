#include <cassert>
#include <sstream>

#include "LinkedList.h"

int main()
{
    LinkedList<int> list;
    assert(list.isEmpty());
    assert(list.length() == 0);

    list.pushFront(2);
    list.pushFront(1);
    list.pushBack(4);
    assert(!list.isEmpty());
    assert(list.length() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 4);

    list.insert(2, 3);
    assert(list.length() == 4);
    assert(list[2] == 3);

    list[2] = 30;
    assert(list[2] == 30);

    list.remove(2);
    assert(list.length() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 4);

    list.remove(0);
    assert(list.length() == 2);
    assert(list[0] == 2);

    int values[] = {5, 6, 7};
    LinkedList<int> fromArray(values, 3);
    assert(fromArray.length() == 3);
    assert(fromArray[0] == 5);
    assert(fromArray[1] == 6);
    assert(fromArray[2] == 7);

    std::ostringstream output;
    output << fromArray;
    assert(output.str() == " -> 5 -> 6 -> 7");
}