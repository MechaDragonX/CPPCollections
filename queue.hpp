#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include "i_link.hpp"
#include "list_node.hpp"

template <typename T>
class Queue : public ILink<T> {
    private:
        DoubleListNode<T>* head_;
        DoubleListNode<T>* tail_;
        int size_;
    public:
        Queue();
        Queue(T value);
        // ~Queue();

        int getSize();

        bool exists(T value) override;
        void add(T value) override;
        void remove() override;
        std::string toString() override;
};

#endif
