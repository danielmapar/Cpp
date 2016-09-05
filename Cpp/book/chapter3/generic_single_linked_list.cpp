#include "generic_single_linked_list.hpp"

template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {}

template <typename E>
bool SLinkedList<E>::empty() const {
  return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {
  return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {
  while(!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
  SNode<E>* v = new SNode<E>;
  v->elem = e;
  v->next = head;
  head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
  SNode<E>* old = head;
  head = old->next;
  delete old;
}

ostream& operator<<(ostream& os, SNode<int>& e) {
  return os << e.elem;
}

ostream& operator<<(ostream& os, SNode<string>& e) {
  return os << e.elem;
}

template <typename E>
void SLinkedList<E>::print() {
  SNode<E>* node = head;
  while(node != NULL) {
    cout << *node << endl;
    node = node->next;
  }
}

int main(void) {
  SLinkedList<int> linkedInt;
  linkedInt.addFront(1);
  linkedInt.addFront(2);
  linkedInt.addFront(3);
  linkedInt.removeFront();
  linkedInt.print();

  SLinkedList<string> linkedString;
  linkedString.addFront("one");
  linkedString.addFront("two");
  linkedString.addFront("three");
  linkedString.removeFront();
  linkedString.print();

}
