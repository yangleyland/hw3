#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};


template <typename T>
Stack<T>::Stack() {

}
template <typename T>
Stack<T>::~Stack() {
}


template <typename T>
bool Stack<T>::empty() const {
    if (std::vector<T>::size()==0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
size_t Stack<T>::size() const {
    size_t value=std::vector<T>::size();
    return value;
}

template <typename T>
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    if (size()==0)
    {
        throw std::underflow_error("Pop function error");
    }
    std::vector<T>::pop_back();
}

//I don't know how to correctly implement the try and catch functions
template <typename T>
const T& Stack<T>::top() const {
    if (size()==0)
    {
        throw std::underflow_error("Top function error");
    }

    return std::vector<T>::back();
}

#endif