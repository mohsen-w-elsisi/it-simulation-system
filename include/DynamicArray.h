#pragma once

template <class T>
class DynamicArray
{
    T *data;
    int capacity;
    int size;

public:
    DynamicArray();
    DynamicArray(int capacity);
    DynamicArray(T *data, int size);
    DynamicArray(const DynamicArray<T> &other);
    DynamicArray(DynamicArray<T> &&other);
    DynamicArray<T> &operator=(DynamicArray<T> &&other);

    ~DynamicArray();

    bool isEmpty() const;
    int length() const;

    void pushBack(T element);

    T &operator[](int i);
    const T &operator[](int i) const;

private:
    void reallocate();
    bool isAtCapacity() const;
};

template <typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), capacity(0), size(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity) : data(new T[capacity]), capacity(capacity), size(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(T *data, int size) : data(data), capacity(size), size(size) {}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
    : data(new T[other.capacity]), capacity(other.capacity), size(other.size)
{
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &&other)
    : data(other.data), capacity(other.capacity), size(other.size)
{
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray<T> &&other)
{
    if (this == &other)
        return *this;

    delete[] data;
    data = other.data;
    capacity = other.capacity;
    size = other.size;

    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;

    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int DynamicArray<T>::length() const
{
    return size;
}

template <typename T>
T &DynamicArray<T>::operator[](int i)
{
    if (i >= size)
        throw "array index out of bounds";
    return data[i];
}

template <typename T>
const T &DynamicArray<T>::operator[](int i) const
{
    if (i >= size)
        throw "array index out of bounds";
    return data[i];
}

template <typename T>
void DynamicArray<T>::pushBack(T element)
{
    if (isAtCapacity())
        reallocate();
    data[size++] = element;
}

template <typename T>
void DynamicArray<T>::reallocate()
{
    int newCapacity = capacity == 0 ? 1 : capacity * 2;
    T *newData = new T[newCapacity];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
bool DynamicArray<T>::isAtCapacity() const
{
    return size == capacity;
}