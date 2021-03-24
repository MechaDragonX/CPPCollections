#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include "student.hpp"

struct ListNode {
    Student value;
    ListNode* previous;
    ListNode* next;
};

class LinkedList {
    private:
        ListNode* head_;
        ListNode* tail_;
        int size_;
    public:
        LinkedList();
        LinkedList(Student value);
        // ~LinkedList();

        ListNode* getHead();
        ListNode* getTail();
        int getSize();

        bool exists(Student value);
        void add(Student value);
        void remove();
        void remove(Student value);
        std::string toString();
};

#endif
