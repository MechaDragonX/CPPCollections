#ifndef I_LINK_HPP
#define I_LINK_HPP

#include <string>

template <typename T>
class ILink {
    public:
        virtual bool exists(T value) = 0;
        virtual void add(T value) = 0;
        virtual void remove() = 0;
        // virtual void remove(T value) = 0;
        virtual std::string toString() = 0;
};

#endif
