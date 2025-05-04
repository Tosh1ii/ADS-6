// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T>
class TPQueue {
 public:
  TPQueue() : head(nullptr) {}

  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T& val) {
    Node* newNode = new Node(val);
    if (!head || val.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next && current->next->data.prior >= val.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }

T pop() {
  if (!head) throw std::runtime_error("Queue is empty");
  Node* temp = head;
  T result = temp->data;
  head = head->next;
  delete temp;
  return result;
}

  const T& front() const {
    if (!head) throw std::runtime_error("Queue is empty");
    return head->data;
  }

  bool isEmpty() const {
    return head == nullptr;
  }

 private:
  struct Node {
    explicit Node(const T& val) : data(val), next(nullptr) {}
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
