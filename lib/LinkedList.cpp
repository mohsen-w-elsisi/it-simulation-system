#include "LinkedList.h"

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
LinkedList<T>::LinkedList() : first(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(T *data, unsigned int length)
{
    if (length == 0)
    {
        first = nullptr;
        return;
    }

    first = new Node<T>(data[0]);
    Node<T> *cur = first;

    for (unsigned int i = 1; i < length; i++)
    {
        cur->next = new Node<T>(data[i]);
        cur = cur->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    /// TODO
}

template <typename T>
int LinkedList<T>::length() const
{
    const Node<T> *curr = first;
    int len = 0;
    while (curr != nullptr)
    {
        len++;
        curr = curr->next;
    }
    return len;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return first == nullptr;
}

template <typename T>
T &LinkedList<T>::operator[](int i)
{
    return nthNode(i)->data;
}

template <typename T>
const T &LinkedList<T>::operator[](int i) const
{
    return nthNode(i)->data;
}

template <typename T>
void LinkedList<T>::pushFront(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->next = first;
    first = newNode;
}

template <typename T>
void LinkedList<T>::pushBack(T data)
{
    Node<T> *newNode = new Node<T>(data);
    last()->next = newNode;
}

template <typename T>
void LinkedList<T>::insert(int i, T data)
{
    Node<T> *nodeBefore = nthNode(i - 1);
    Node<T> *nodeAfter = nodeBefore->next;
    nodeBefore->next = new Node<T>(data);
    nodeBefore->next->next = nodeAfter;
}

template <typename T>
void LinkedList<T>::remove(int i)
{
    if (i == 0)
    {
        Node<T> *sndNode = first->next;
        delete first;
        first = sndNode;
        return;
    }

    Node<T> *nodeBefore = nthNode(i - 1);
    Node<T> *nodeToDelete = nodeBefore->next;
    nodeBefore->next = nodeToDelete->next;
    delete nodeToDelete;
}

template <typename T>
Node<T> *LinkedList<T>::last()
{
    if (isEmpty())
        throw 0;

    Node<T> *curr = first;
    while (curr->next != nullptr)
        curr = curr->next;
    return curr;
}

template <typename T>
Node<T> *LinkedList<T>::nthNode(int n)
{
    if (n == 0)
        return first;

    Node<T> *curr = first;
    for (int i = 1; i <= n; i++)
    {
        curr = curr->next;
        if (curr == nullptr)
            throw 1;
    }
    return curr;
}

template <typename T>
const Node<T> *LinkedList<T>::nthNode(int n) const
{
    if (n == 0)
        return first;

    const Node<T> *curr = first;
    for (int i = 1; i <= n; i++)
    {
        curr = curr->next;
        if (curr == nullptr)
            throw 1;
    }
    return curr;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const LinkedList<T> &list)
{
    for (int i = 0; i < list.length(); i++)
        stream << " -> " << list[i];
    return stream;
}

template class LinkedList<int>;
template std::ostream &operator<<(std::ostream &, const LinkedList<int> &);
