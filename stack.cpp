#include <iostream>
#include <string>
#include <type_traits>
#include "i_link.hpp"
#include "list_node.hpp"
#include "stack.hpp"
#include "student.hpp"

template <typename T>
Stack<T>::Stack() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}
template <typename T>
Stack<T>::Stack(T value) {
    tail_ = nullptr;
    head_ = new DoubleListNode<T>{ value, nullptr, tail_ };
    size_ = 1;
}
// template <typename T>
// Stack<T>::~Stack() {}

template <typename T>
int Stack<T>::getSize() {
    return size_;
}

template <typename T>
bool Stack<T>::exists(T value) {
    DoubleListNode<T>* current = head_;
    while(current != nullptr) {
        if(current->value == value)
            return true;

        current = current->next;
    }
    return false;
}
template <typename T>
void Stack<T>::add(T value) {
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
// Remove from end (conceptually "the top")
template <typename T>
void Stack<T>::remove() {
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
std::string Stack<T>::toString() {
    DoubleListNode<T>* current = tail_;
    std::string output = "";
    // Print each element backwards so it looks like the back is facing the element in front of it
    while(current != nullptr) {
        // If type is Student
        if constexpr (std::is_same<T, Student>::value)
            output += current->value.toString(false) + "\n";
        // If type is std::string
        else if constexpr (std::is_same<T, std::string>::value)
            output += current->value + "\n";
        // Otherwise, it's a primitive
        else
            output += std::to_string(current->value) + "\n";

        current = current->previous;
    }
    return output;
}

// Relevant Templates
template class Stack<int>;
template class Stack<char>;
template class Stack<bool>;
template class Stack<float>;
template class Stack<double>;
template class Stack<wchar_t>;
template class Stack<std::string>;
template class Stack<Student>;
