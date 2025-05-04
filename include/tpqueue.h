// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template <typename T>
class TPQueue {
 public:
  TPQueue() : head(nullptr) {}

  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T& element) {
    Node* newNode = new Node(element);
    if (!head || element.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next && current->next->data.prior >= element.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }

  T pop() {
   if (!head) {
    throw std::string("Is empty");
   }
   T res = head->data;
   Node* element = head;
   head = head->next;
   delete element;
   return res;
  }

  const T& front() const {
    if (!head) throw std::runtime_error("Is empty");
    return head->data;
  }

  bool isEmpty() const {
    return head == nullptr;
  }

 private:
  struct Node {
    explicit Node(const T& element) : data(element), next(nullptr) {}
    T data;
    Node* next;
  };

  Node* head;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
