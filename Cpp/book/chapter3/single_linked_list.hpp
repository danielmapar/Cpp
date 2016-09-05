#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class StringNode {
  string elem;
  StringNode* next;

  friend ostream& operator<<(ostream& os, const StringNode& node);

  /* When we define an input or output operator that conforms to
  the conventions of the iostream library, we must make it a nonmember operator.
  We cannot make the operator a member of our own class. If we did, then the
  left-hand operand would have to be an object of our class type
  ostream& operator<<(ostream& os, const StringNode& node);*/
  friend class StringLinkedList;
};

class StringLinkedList {
public:
  StringLinkedList();
  ~StringLinkedList();
  bool empty() const;
  const string& front() const;
  void addFront(const string& e);
  void print();
  void removeFront();
private:
  StringNode* head;
};
