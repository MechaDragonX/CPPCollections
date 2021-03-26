#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <string>
#include "i_link.hpp"

template <typename T>
struct DoubleListNode {
    T value;
    DoubleListNode<T>* previous;
    DoubleListNode<T>* next;
};

template <typename T>
class DoubleLinkedList : public ILink<T> {
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

        bool exists(T value) override;
        void add(T value) override;
        void remove() override;
        void remove(T value) override;
        std::string toString();
};

#endif
