#include <string>
#include "linked_list.hpp"
#include "student.hpp"

LinkedList::LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

ListNode* LinkedList::getHead() {
    return head_;
}
ListNode* LinkedList::getTail() {
    return tail_;
}
int LinkedList::getSize() {
    return size_;
}

void LinkedList::add(Student value) {
    if(head_ == nullptr)
        head_ = new ListNode{ value, nullptr, tail_ };
        // tail = nullptr in this case
    else if(size_ == 1) {
        tail_ = new ListNode{ value, head_, nullptr };
        head_->next = tail_;
    }
    else {
        ListNode* neo = new ListNode{ value, tail_, nullptr };
        tail_->next = neo;
        tail_ = neo;
    }

    size_++;
}
Student LinkedList::remove() {
    ListNode* oldTail = tail_;
    tail_ = tail_->previous;
    tail_->next = nullptr;
    size_--;

    return oldTail->value;
    delete oldTail;
}
Student LinkedList::remove(Student value) {
    ListNode* current = head_;
    // ListNode* previous = nullptr;
    // ListNode* next = nullptr;
    while(current != nullptr) {
        if(current->value == value) {
            // If there is are values 1, 2, 3 that are linked to each other,
            // 1 => 3
            current->previous->next = current->next;
            // 1 <=  3
            current->next->previous = current->previous;
            size_--;

            // Return the value
            return current->value;
            // Delete the removed node
            delete current;
        }
        current = current->next;
    }
    return Student();
}
std::string LinkedList::toString() {
    ListNode* current = head_;
    std::string output = "";
    while(current != nullptr) {
        if(current->next != nullptr)
            output += current->value.toString(false) + " => ";
        else
            output += current->value.toString(false);

        current = current->next;
    }
    return output;
}
