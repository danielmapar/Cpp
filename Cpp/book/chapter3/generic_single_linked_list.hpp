#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename E>
class SLinkedList;

template <typename E>
class SNode {
private:
  E elem;
  SNode<E>* next;
  friend class SLinkedList<E>;
  // http://stackoverflow.com/questions/4014294/operator-overloading-on-class-templates
  friend ostream& operator<<(ostream& os, SNode<int>& e);
  friend ostream& operator<<(ostream& os, SNode<string>& e);
};

template <typename E>
class SLinkedList {
public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  const E& front() const;
  void addFront(const E& e);
  void removeFront();
  void print();
private:
  SNode<E>* head;
};
