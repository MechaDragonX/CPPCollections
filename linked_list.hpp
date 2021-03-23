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
        // LinkedList(ListNode head);
        // LinkedList(Student value);
        // ~LinkedList();

        int getSize();

        void add(Student value);
        Student remove();
        Student remove(Student value);
        std::string toString();
};

#endif
