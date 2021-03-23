#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include "student.hpp"

struct ListNode {
    Student value;
    ListNode* back;
    ListNode* front;
};

class LinkedList {
    private:
        ListNode* head_;
        ListNode* tail_;
        int size;
    public:
        LinkedList();
        // LinkedList(ListNode head);
        // LinkedList(Student element);
        ~LinkedList();

        int getSize();

        void add(Student element);
        Student remove();
        std::string toString();
};

#endif
