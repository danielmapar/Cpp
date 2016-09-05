#include "generic_double_linked_list.hpp"

#ifndef IOSTREAM
  #include <iostream>
  #define IOSTREAM 1
#endif
#include <string>

using std::string;
using std::cout;
using std::endl;

template <typename T>
Node<T>::Node(T *elem) {
  this->elem = elem;
  next = NULL;
  prev = NULL;
}

template <typename T>
Node<T>::~Node() {
  cout << "Destroying node!" << endl;
  delete elem;
  next = NULL;
  prev = NULL;
}

template <typename T>
T Node<T>::getElement() {
  return *elem;
}

template <typename T>
void Node<T>::setElement(T *elem) {
  this->elem = elem;
}

template <typename T>
void Node<T>::setNext(Node<T> *node) {
  this->next = node;
}

template <typename T>
Node<T>* Node<T>::getNext() {
  return next;
}

template <typename T>
void Node<T>::setPrev(Node<T> *node) {
  this->prev = node;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
  return prev;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(Node<T> *node) {
  this->head = new Node<T>(NULL);
  this->tail = new Node<T>(NULL);

  this->head->setNext(node);
  this->tail->setPrev(node);
}

template <typename T>
bool DoubleLinkedList<T>::empty() {
  if (this->head->getNext() == NULL || this->tail->getPrev() == NULL) {
    return true;
  }
  return false;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  while(!empty()) {
    removeLast();
  }
  delete this->head;
  delete this->tail;
  cout << "Delete double linked list" << endl;
}

template <typename T>
Node<T>* DoubleLinkedList<T>::getHead() {
  return this->head;
}

template <typename T>
Node<T>* DoubleLinkedList<T>::getTail() {
  return this->tail;
}

template <typename T>
void DoubleLinkedList<T>::addFront(Node<T> *newNode) {
  Node<T> *tail = this->getTail();
  Node<T> *lastNode = tail->getPrev();
  if (lastNode != NULL) {
    lastNode->setNext(newNode);
    newNode->setPrev(lastNode);
    newNode->setNext(tail);
    tail->setPrev(newNode);
  } else {
    this->head->setNext(newNode);
    this->tail->setPrev(newNode);
    newNode->setPrev(this->head);
    newNode->setNext(this->tail);
  }
}

template <typename T>
void DoubleLinkedList<T>::removeLast() {
  if (this->head->getNext() == this->tail->getPrev()) {
    cout << "List will be empty!" << endl;
    delete this->head->getNext();
    this->head->setNext(NULL);
    this->tail->setPrev(NULL);
  } else {
    Node<T> *tail = this->getTail();
    Node<T> *lastNode = tail->getPrev();
    Node<T> *newLastNode = lastNode->getPrev();

    delete lastNode;

    tail->setPrev(newLastNode);
    newLastNode->setNext(tail);
  }
}

template <typename T>
void DoubleLinkedList<T>::print() {
  Node<T> *node = this->getHead()->getNext();
  while (node != NULL) {
    cout << node->getElement() << endl;
    if ((node = node->getNext()) == this->tail) {
      break;
    }
  }
}

int main(void) {
  Node<string> *node = new Node<string>(new string("one"));
  node->setElement(new string("uno"));

  Node<string> *node2 = new Node<string>(new string("two"));

  DoubleLinkedList<string> *list = new DoubleLinkedList<string>(node);
  list->addFront(node2);
  list->addFront(new Node<string>(new string("three")));

  list->print();

  list->removeLast();
  list->removeLast();
  list->removeLast();

  list->addFront(new Node<string>(new string("I'am alive!!!")));
  list->print();

  delete list;

  return 0;
}
