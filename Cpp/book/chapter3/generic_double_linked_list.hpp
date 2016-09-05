#include <iostream>

#define IOSTREAM 1

template <typename T>
class Node {
private:
  T *elem;
  Node *next;
  Node *prev;
public:
  Node(T *elem);
  ~Node();
  void setNext(Node<T> *node);
  void setPrev(Node<T> *node);
  void setElement(T *elem);
  T getElement();
  Node<T>* getNext();
  Node<T>* getPrev();
};

template <typename T>
class DoubleLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
public:
  DoubleLinkedList(Node<T> *node);
  ~DoubleLinkedList();
  void addFront(Node<T> *node);
  void removeLast();
  bool empty();
  void print();
  Node<T>* getTail();
  Node<T>* getHead();
};
