#pragma once

#include <ostream>

template <typename T>
struct Node;

template <typename T>
class LinkedList
{
    Node<T> *first;

public:
    LinkedList();
    LinkedList(T *data, unsigned int length);
    ~LinkedList();

    int length() const;
    bool isEmpty() const;
    T &operator[](int i);
    const T &operator[](int i) const;
    void pushFront(T data);
    void pushBack(T data);
    void insert(int i, T data);
    void remove(int i);

private:
    Node<T> *last();
    Node<T> *nthNode(int n);
    const Node<T> *nthNode(int n) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const LinkedList<T> &list);
