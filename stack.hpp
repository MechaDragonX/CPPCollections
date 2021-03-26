#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include "i_link.hpp"
#include "list_node.hpp"

template <typename T>
class Stack : public ILink<T> {
    private:
        DoubleListNode<T>* head_;
        DoubleListNode<T>* tail_;
        int size_;
    public:
        Stack();
        Stack(T value);
        // ~Stack();

        int getSize();

        bool exists(T value) override;
        void add(T value) override;
        void remove() override;
        std::string toString() override;
};

#endif
