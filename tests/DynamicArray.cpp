#include <cassert>
#include "DynamicArray.h"

int main()
{
    DynamicArray<int> array;
    assert(array.isEmpty());

    array.pushBack(10);
    array.pushBack(20);
    array.pushBack(30);

    assert(!array.isEmpty());
    assert(array[0] == 10);
    assert(array[1] == 20);
    assert(array[2] == 30);

    const DynamicArray<int> &constArray = array;
    assert(constArray[0] == 10);
    assert(constArray[2] == 30);

    DynamicArray<int> preallocated(2);
    assert(preallocated.isEmpty());
    preallocated.pushBack(1);
    preallocated.pushBack(2);
    preallocated.pushBack(3);

    assert(preallocated[0] == 1);
    assert(preallocated[1] == 2);
    assert(preallocated[2] == 3);
}
