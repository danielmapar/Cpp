#include "single_linked_list.hpp"

StringLinkedList::StringLinkedList() : head(NULL) {}

StringLinkedList::~StringLinkedList() {
  while(!empty()) removeFront();
}

bool StringLinkedList::empty() const {
  return head == NULL;
}

const string& StringLinkedList::front() const {
  return head->elem;
}

void StringLinkedList::addFront(const string& e) {
  StringNode* v = new StringNode;
  v->elem = e;
  // copying address from head to next (address is fine, value is different)
  v->next = head;
  head = v;
}

void StringLinkedList::removeFront() {
  StringNode* old = head;
  head = old->next;
  delete old;
}

void StringLinkedList::print() {
  StringNode* node = head;
  while(node != NULL) {
    cout << *node << endl;
    node = node->next;
  }
}

ostream& operator<<(ostream& os, const StringNode& node) {
  return os << node.elem;
}

int main(void) {
  StringLinkedList linkedList;
  linkedList.addFront("test1");
  linkedList.addFront("test2");
  linkedList.addFront("test3");
  linkedList.addFront("test4");
  linkedList.removeFront();
  linkedList.print();
  return 0;
}
