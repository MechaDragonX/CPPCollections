#include <iostream>
#include <string>
#include "linked_list.hpp"
#include "student.hpp"

LinkedList::LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}
LinkedList::LinkedList(Student value) {
    tail_ = nullptr;
    head_ = new ListNode{ value, nullptr, tail_ };
    size_ = 1;
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

bool LinkedList::exists(Student value) {
    ListNode* current = head_;
    while(current != nullptr) {
        if(current->value == value)
            return true;

        current = current->next;
    }
    return false;
}
void LinkedList::add(Student value) {
    if(head_ == nullptr)
        head_ = new ListNode{ value, nullptr, tail_ };
        // tail = nullptr in this case
    else if(size_ == 1) {
        // Set tail to new value
        tail_ = new ListNode{ value, head_, nullptr };
        // Make head => tail (forward link)
        head_->next = tail_;
    }
    else {
        // Make a new node with the passed value that is backward linked to tail and forward linked to nullptr
        ListNode* neo = new ListNode{ value, tail_, nullptr };
        // Make tail => neo
        tail_->next = neo;
        // Make neo the new tail
        tail_ = neo;
    }

    size_++;
}
void LinkedList::remove() {
    ListNode* oldTail = tail_;
    // Make tail the previous value
    tail_ = tail_->previous;
    // Forward link it to nullptr
    tail_->next = nullptr;
    // decrement size
    size_--;

    delete oldTail;
}
void LinkedList::remove(Student value) {
    if(head_->value == value) {
        ListNode* oldHead = head_;
        head_ = head_->next;
        head_->previous = nullptr;
        delete oldHead;
        size_--;
        return;
    }

    ListNode* current = head_;
    while(current != nullptr) {
        if(current->value == value) {
            // If there is are values 1, 2, 3 that are linked to each other,
            // 1 => 3
            current->previous->next = current->next;
            // 1 <=  3 (backward link)
            current->next->previous = current->previous;

            // Delete the removed node
            delete current;
            size_--;
        }
        current = current->next;
    }
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
