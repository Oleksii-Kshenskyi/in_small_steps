#ifndef CLFIXEDQUEUE_H
#define CLFIXEDQUEUE_H

#include <queue>
#include <deque>
#include <iostream>

template <typename T, int MaxLen, typename Container=std::deque<T>>
class CLFixedQueue : public std::queue<T, Container> {
public:
    void push(const T& value)
    {
        if (this->size() == MaxLen)
        {
           this->c.pop_front();
        }
        std::queue<T, Container>::push(value);
    }
};

#endif // CLFIXEDQUEUE_H
