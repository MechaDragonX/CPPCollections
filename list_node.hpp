#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

template <typename T>
struct ListNode {
    T value;
    ListNode<T>* next;
};

template <typename T>
struct DoubleListNode {
    T value;
    DoubleListNode<T>* previous;
    DoubleListNode<T>* next;
};

#endif
