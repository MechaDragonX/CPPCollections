#include <iostream>
#include <string>
#include <type_traits>
#include "double_linked_list.hpp"
#include "student.hpp"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(T value) {
    tail_ = nullptr;
    head_ = new DoubleListNode<T>{ value, nullptr, tail_ };
    size_ = 1;
}
// template <typename T>
// DoubleLinkedList<T>::~DoubleLinkedList() {
//     DoubleListNode* current = tail_;
//     DoubleListNode* toDelete = nullptr;
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
DoubleListNode<T>* DoubleLinkedList<T>::getHead() {
    return head_;
}
template <typename T>
DoubleListNode<T>* DoubleLinkedList<T>::getTail() {
    return tail_;
}
template <typename T>
int DoubleLinkedList<T>::getSize() {
    return size_;
}

template <typename T>
bool DoubleLinkedList<T>::exists(T value) {
    DoubleListNode<T>* current = head_;
    while(current != nullptr) {
        if(current->value == value)
            return true;

        current = current->next;
    }
    return false;
}
template <typename T>
void DoubleLinkedList<T>::add(T value) {
    if(head_ == nullptr)
        head_ = new DoubleListNode<T>{ value, nullptr, tail_ };
        // tail = nullptr in this case
    else if(size_ == 1) {
        // Set tail to new value
        tail_ = new DoubleListNode<T>{ value, head_, nullptr };
        // Make head => tail (forward link)
        head_->next = tail_;
    }
    else {
        // Make a new node with the passed value that is backward linked to tail and forward linked to nullptr
        DoubleListNode<T>* neo = new DoubleListNode<T>{ value, tail_, nullptr };
        // Make tail => neo
        tail_->next = neo;
        // Make neo the new tail
        tail_ = neo;
    }

    size_++;
}
template <typename T>
void DoubleLinkedList<T>::remove() {
    DoubleListNode<T>* oldTail = tail_;
    // Make tail the previous value
    tail_ = tail_->previous;
    // Forward link it to nullptr
    tail_->next = nullptr;
    // decrement size
    size_--;

    delete oldTail;
}
template <typename T>
void DoubleLinkedList<T>::remove(T value) {
    if(head_->value == value) {
        DoubleListNode<T>* oldHead = head_;
        head_ = head_->next;
        head_->previous = nullptr;
        delete oldHead;
        size_--;
        return;
    }

    DoubleListNode<T>* current = head_;
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
std::string DoubleLinkedList<T>::toString() {
    DoubleListNode<T>* current = head_;
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
template class DoubleLinkedList<int>;
template class DoubleLinkedList<char>;
template class DoubleLinkedList<bool>;
template class DoubleLinkedList<float>;
template class DoubleLinkedList<double>;
template class DoubleLinkedList<wchar_t>;
template class DoubleLinkedList<std::string>;
template class DoubleLinkedList<Student>;
