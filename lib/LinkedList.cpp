#include <ostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    Node<T> *first;

public:
    LinkedList() : first(nullptr) {}
    LinkedList(T *data, unsigned int length)
    {
        if (length == 0)
            first = nullptr;

        first = new Node(data[0]);
        Node<T> *cur = first;

        for (int i = 1; i < length; i++)
        {
            cur->next = new Node(data[i]);
            cur = cur->next;
        }
    }

    ~LinkedList()
    {
        // TODO: no destructor here
    }

    int length() const
    {
        Node<T> *curr = first;
        int len = 0;
        while (curr != nullptr)
        {
            len++;
            curr = curr->next;
        }
        return len;
    }

    bool isEmpty() const
    {
        return first == nullptr;
    }

    T &operator[](int i)
    {
        return nthNode(i)->data;
    }

    const T &operator[](int i) const
    {
        return nthNode(i)->data;
    }

    void pushFront(T data)
    {
        Node<T> *newNode = new Node(data);
        newNode->next = first;
        first = newNode;
    }

    void pushBack(T data)
    {
        Node<T> *newNode = new Node(data);
        last()->next = newNode;
    }

    void insert(int i, T data)
    {
        Node<T> *nodeBefore = nthNode(i - 1);
        Node<T> *nodeAfter = nodeBefore->next;
        nodeBefore->next = new Node(data);
        nodeBefore->next->next = nodeAfter;
    }

    void remove(int i)
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

    template <typename U>
    friend ostream &operator<<(ostream &stream, const LinkedList<U> &list);

private:
    Node<T> *
    last()
    {
        if (isEmpty())
            throw 0;
        Node<T> *curr = first;
        while (curr->next != nullptr)
            curr = curr->next;
        return curr;
    }

    Node<T> *nthNode(int n)
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

    const Node<T> *nthNode(int n) const
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
};

template <typename T>
ostream &operator<<(ostream &stream, const LinkedList<T> &list)
{
    for (int i = 0; i < list.length(); i++)
    {
        const T data = list[i];
        stream << " -> " << data;
    }
    return stream;
}
