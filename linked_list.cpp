#include <iostream>
#include <string>
#include <type_traits>
#include "i_link.hpp"
#include "linked_list.hpp"
#include "list_node.hpp"
#include "student.hpp"

template <typename T>
LinkedList<T>::LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}
template <typename T>
LinkedList<T>::LinkedList(T value) {
    tail_ = nullptr;
    head_ = new ListNode<T>{ value, tail_ };
    size_ = 1;
}
// template <typename T>
// LinkedList<T>::~LinkedList() {}

template <typename T>
ListNode<T>* LinkedList<T>::getHead() {
    return head_;
}
template <typename T>
ListNode<T>* LinkedList<T>::getTail() {
    return tail_;
}
template <typename T>
int LinkedList<T>::getSize() {
    return size_;
}

template <typename T>
bool LinkedList<T>::exists(T value) {
    ListNode<T>* current = head_;
    while(current != nullptr) {
        if(current->value == value)
            return true;

        current = current->next;
    }
    return false;
}
template <typename T>
void LinkedList<T>::add(T value) {
    if(head_ == nullptr)
        head_ = new ListNode<T>{ value, tail_ };
        // tail = nullptr in this case
    else if(size_ == 1) {
        // Set tail to new value
        tail_ = new ListNode<T>{ value, nullptr };
        // Make head => tail (forward link)
        head_->next = tail_;
    }
    else {
        // Make a new node with the passed value that is forward linked to nullptr
        ListNode<T>* neo = new ListNode<T>{ value, nullptr };
        // Make tail => neo
        tail_->next = neo;
        // Make neo the new tail
        tail_ = neo;
    }

    size_++;
}
template <typename T>
void LinkedList<T>::remove() {
    ListNode<T>* oldTail = tail_;
    ListNode<T>* previous = head_;

    while(previous->next != tail_)
        previous = previous->next;

    previous->next = nullptr;
    delete oldTail;

    size_--;
}
template <typename T>
void LinkedList<T>::remove(T value) {
    if(head_->value == value) {
        ListNode<T>* oldHead = head_;
        head_ = head_->next;
        delete oldHead;
        size_--;
        return;
    }

    ListNode<T>* previous = head_;
    ListNode<T>* current = head_->next;
    while(current != nullptr) {
        if(current->value == value) {
            // Make previous's next, current's next
            previous->next = current->next;
            // Delete the removed node
            delete current;
            size_--;
        }
        current = current->next;
    }
}
template <typename T>
std::string LinkedList<T>::toString() {
    ListNode<T>* current = head_;
    std::string output = "";
    while(current != nullptr) {
        if(current->next != nullptr) {
            // If type is Student
            if constexpr (std::is_same<T, Student>::value)
                output += current->value.toString(false) + " => ";
            // If type is std::string
            else if constexpr (std::is_same<T, std::string>::value)
                output += current->value + " => ";
            // Otherwise, it's a primitive
            else
                output += std::to_string(current->value) + " => ";
        }
        else {
            // If type is Student
            if constexpr (std::is_same<T, Student>::value)
                output += current->value.toString(false);
            // If type is std::string
            else if constexpr (std::is_same<T, std::string>::value)
                output += current->value;
            // Otherwise, it's a primitive
            else
                output += std::to_string(current->value);
        }

        current = current->next;
    }
    return output;
}

// Relevant Templates
template class LinkedList<int>;
template class LinkedList<char>;
template class LinkedList<bool>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<wchar_t>;
template class LinkedList<std::string>;
template class LinkedList<Student>;
