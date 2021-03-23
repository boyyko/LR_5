// Copyright 2020 Your Name <your_email>
// Created by ubuntu on 16.03.2021.

#ifndef INCLUDE_STACK_2_HPP_
#define INCLUDE_STACK_2_HPP_

#include "stack_1.hpp"
#include <utility>

template <typename T>
class stack_2 {
 private:
  data<T>* top_element;

 public:
  stack_2() : top_element(nullptr) {}
  stack_2(stack_2& stack_2) = delete;  // запрещаем конструктор копирования
  stack_2(stack_2&& stack_2) = default;
  stack_2& operator=(stack_2& stack_2) = delete;
  stack_2& operator=(stack_2&& stack_2) = default;

  template <typename... Args>
  void push_emplace(Args&&... value)
  {
    top_element = new data<T>{{std::forward<Args>(value)...}, top_element};
  }

  void push(T&& value)
  {
    top_element = new data<T>{std::forward<T>(value), top_element};
  }

  const T& head() const
  {
    if (!top_element) throw std::runtime_error("Stack is empty!");
    return top_element->d;
  }

  T pop()
  {
    if (!top_element) throw std::runtime_error("Stack is empty!");
    data<T>* delete_node = top_element;
    T data = std::move(top_element->d);
    top_element = delete_node->next_element;
    delete delete_node;
    return data;
  }

  ~stack_2()
  {
    while (top_element)
    {
      data<T>* delete_data = top_element;
      top_element = delete_data->next_element;
      delete delete_data;
    }
  }
};


#endif  // INCLUDE_STACK_2_HPP_
