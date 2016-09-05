#include <iostream>
#include <cstdlib>

template <typename T>
class List;

template <typename T>
class Node {
  private:
    T *element;
    Node<T> *next;
  public:
    Node(T *elem) : element(elem), next(NULL) {};
    ~Node();
    void setNext(Node<T> *node);
    friend class List<T>;
};

template <typename T>
class List {
  private:
    Node<T> *head;
    Node<T> *back;
  public:
    List(Node<T> *node);
    ~List();
    void addNode(Node<T> *newNode);
    void printList();
};
