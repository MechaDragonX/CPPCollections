#include <iostream>
#include <string>
#include <type_traits>
#include "i_link.hpp"
#include "list_node.hpp"
#include "queue.hpp"
#include "student.hpp"

template <typename T>
Queue<T>::Queue() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}
template <typename T>
Queue<T>::Queue(T value) {
    tail_ = nullptr;
    head_ = new DoubleListNode<T>{ value, nullptr, tail_ };
    size_ = 1;
}
// template <typename T>
// Queue<T>::~Queue() {}

template <typename T>
int Queue<T>::getSize() {
    return size_;
}

template <typename T>
bool Queue<T>::exists(T value) {
    DoubleListNode<T>* current = head_;
    while(current != nullptr) {
        if(current->value == value)
            return true;

        current = current->next;
    }
    return false;
}
template <typename T>
void Queue<T>::add(T value) {
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
        // Make a new node with the passed value that is forward linked to nullptr
        DoubleListNode<T>* neo = new DoubleListNode<T>{ value, tail_, nullptr };
        // Make tail => neo
        tail_->next = neo;
        // Make neo the new tail
        tail_ = neo;
    }

    size_++;
}
// Remove from front
template <typename T>
void Queue<T>::remove() {
    DoubleListNode<T>* oldHead = head_;
    // Make value after head point back to nullptr
    head_->next->previous = nullptr;
    delete oldHead;
}
template <typename T>
std::string Queue<T>::toString() {
    DoubleListNode<T>* current = tail_;
    std::string output = "";
    // Print each element backwards so it looks like the back is facing the element in front of it
    while(current != nullptr) {
        if(current->previous != nullptr) {
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

        current = current->previous;
    }
    return output;
}

// Relevant Templates
template class Queue<int>;
template class Queue<char>;
template class Queue<bool>;
template class Queue<float>;
template class Queue<double>;
template class Queue<wchar_t>;
template class Queue<std::string>;
template class Queue<Student>;
