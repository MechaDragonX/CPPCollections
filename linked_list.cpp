#include <iostream>
#include <string>
#include <type_traits>
#include "linked_list.hpp"
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
    head_ = new ListNode<T>{ value, nullptr, tail_ };
    size_ = 1;
}
// template <typename T>
// LinkedList<T>::~LinkedList() {
//     ListNode* current = tail_;
//     ListNode* toDelete = nullptr;
//     while(current->previous != nullptr) {
//         std::cout << current->value.toString(false) + ", ";
//         current = current->previous;
//         toDelete = current->next;
//         current->next = nullptr;
//         delete toDelete;
//     }
//     head_ = nullptr;
//     tail_ = nullptr;
//     size_ = 0;
// }

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
        head_ = new ListNode<T>{ value, nullptr, tail_ };
        // tail = nullptr in this case
    else if(size_ == 1) {
        // Set tail to new value
        tail_ = new ListNode<T>{ value, head_, nullptr };
        // Make head => tail (forward link)
        head_->next = tail_;
    }
    else {
        // Make a new node with the passed value that is backward linked to tail and forward linked to nullptr
        ListNode<T>* neo = new ListNode<T>{ value, tail_, nullptr };
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
    // Make tail the previous value
    tail_ = tail_->previous;
    // Forward link it to nullptr
    tail_->next = nullptr;
    // decrement size
    size_--;

    delete oldTail;
}
template <typename T>
void LinkedList<T>::remove(T value) {
    if(head_->value == value) {
        ListNode<T>* oldHead = head_;
        head_ = head_->next;
        head_->previous = nullptr;
        delete oldHead;
        size_--;
        return;
    }

    ListNode<T>* current = head_;
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
template <typename T>
std::string LinkedList<T>::toString() {
    ListNode<T>* current = head_;
    std::string output = "";
    // Blank string to compare all types to see if the current type is a string
    std::string comparer = "";
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
