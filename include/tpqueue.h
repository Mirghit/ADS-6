// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Node {
      T data;
      Node* next;
      Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };
    Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push(const T& item) {
    Node* newNode = new Node(item);
    if (!head || item.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      return;
    }
    Node* curr = head;
    while (curr->next && curr->next->data.prior >= item.prior) {
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }

  T pop() {
    Node* temp = head;
    T result = head->data;
    head = head->next;
    delete temp;
    return result;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
