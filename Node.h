#ifndef NODE_H
#define NODE_H
#include "Student.h"
class Node{
 public:
  //methods
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
  Node(Student*);
  ~Node();
 private:
  //member variables5D5C5D
  Student* student;
  Node* next;
  
};
#endif
