// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_STACK_1_HPP_
#define INCLUDE_STACK_1_HPP_

#include <iostream>

template <typename T>
struct data
{
  T d;
  data* next_element;
};

template <typename T>
class stack_1 {
 public:
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  ~stack_1()
  {
    while (top_element)
    {
      data<T> *delete_data = top_element;
      top_element = delete_data->next_element;
      delete delete_data;
    }
  }

  bool empty() const {
    return top_element == nullptr;
  }

  stack_1() :
  top_element(nullptr)
  {};
  stack_1(const stack_1& s) = delete; // не копируемый коструктор
  stack_1(stack_1&& s) = default;
  stack_1&operator=(const stack_1& s) = delete;
  stack_1&operator=(stack_1&& s)  = default;

 private:
  data<T> *top_element;
};

template <typename T>
const T& stack_1<T>::head() const
{
  if (empty())
  {
    throw std::runtime_error("Empty");
  }
  return top_element->d;
}


template <typename T>
void stack_1<T>::push(T&& value)
{
  data<T>* new_data = new data<T>;
  new_data->d = value;
  new_data->next_element = top_element;
  top_element = new_data;
}

template <typename T>
void stack_1<T>::push(const T& value)
{
  data<T>* new_data = new data<T>;
  new_data->d = value;
  new_data->next_element = top_element;
  top_element = new_data;
}

template <typename T>
void stack_1<T>::pop()
{
  if (empty())
  {
    throw std::runtime_error("ERROR");
  } else {
    data<T> *delete_data = top_element;
    top_element = delete_data->next_element;
    delete delete_data;
  }
}





#endif // INCLUDE_STACK_1_HPP_
