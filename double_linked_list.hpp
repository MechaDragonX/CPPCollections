#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <string>

template <typename T>
struct DoubleListNode {
    T value;
    DoubleListNode<T>* previous;
    DoubleListNode<T>* next;
};

template <typename T>
class DoubleLinkedList {
    private:
        DoubleListNode<T>* head_;
        DoubleListNode<T>* tail_;
        int size_;
    public:
        DoubleLinkedList();
        DoubleLinkedList(T value);
        // ~DoubleLinkedList();

        DoubleListNode<T>* getHead();
        DoubleListNode<T>* getTail();
        int getSize();

        bool exists(T value);
        void add(T value);
        void remove();
        void remove(T value);
        std::string toString();
};

#endif
