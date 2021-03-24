#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>

template <typename T>
struct ListNode {
    T value;
    ListNode<T>* previous;
    ListNode<T>* next;
};

template <typename T>
class LinkedList {
    private:
        ListNode<T>* head_;
        ListNode<T>* tail_;
        int size_;
    public:
        LinkedList();
        LinkedList(T value);
        // ~LinkedList();

        ListNode<T>* getHead();
        ListNode<T>* getTail();
        int getSize();

        bool exists(T value);
        void add(T value);
        void remove();
        void remove(T value);
        std::string toString();
};

#endif
