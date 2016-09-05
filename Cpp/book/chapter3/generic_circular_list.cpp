#include "generic_circular_list.hpp"

using std::cout;
using std::endl;
using std::string;

// Node
template <typename T>
Node<T>::~Node() {
  delete element;
};

template <typename T>
void Node<T>::setNext(Node<T> *node) {
  next = node;
};

// List
template <typename T>
List<T>::~List() {
  Node<T> *node = head;
  Node<T> *next = NULL;
  while (node != NULL) {
    next = node->next;
    delete node;
    node = next;
  }
};

template <typename T>
void List<T>::printList() {
  Node<T> *node = head;
  while (node != NULL) {
    cout << *(node->element) << endl;
    if (node->next == head) {
      break;
    }
    node = node->next;
  }
}

template <typename T>
void List<T>::addNode(Node<T> *newNode) {
  Node<T> *node = head;
  while (node != NULL) {
    if (node->next == head) {
      node->next = newNode;
      newNode->next = head;
      break;
    }
    node = node->next;
  }
}

template <typename T>
List<T>::List(Node<T> *node) : head(node), back(node) {
  head->next = node;
  back->next = head;
};

int main(void) {

  Node<string> *node1 = new Node<string>(new string("0"));
  List<string> *circularList = new List<string>(node1);

  circularList->addNode(new Node<string>(new string("1")));
  circularList->addNode(new Node<string>(new string("2")));
  circularList->addNode(new Node<string>(new string("3")));
  circularList->addNode(new Node<string>(new string("4")));
  circularList->addNode(new Node<string>(new string("5")));
  circularList->addNode(new Node<string>(new string("6")));

  circularList->printList();

  int val = 10;
  int &val_ref = val;
  val_ref++;
  cout << val << endl;

  return 0;
}
