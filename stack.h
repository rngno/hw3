#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> // PRIVATE!! don't want users to use something that breaks stack operations
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

template<typename T>
bool Stack<T>::empty() const{
  return std::vector<T>::empty();
}

size_t Stack<T>::size() const{
  return std::vector<T>::size();
}

template<typename T>
void Stack<T>::push(const T& item){
  this->push_back(item);
}

void Stack<T>::pop(){
  this->pop_back();
}

template<typename T>
const T& Stack<T>::top() const{
  return this->back();
}

#endif
