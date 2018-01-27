#ifndef STUDENT_H
#define STUDENT_H
#include <cstring>
#include <iostream>

using namespace std;

class Student {
 public:
  Student(char* newFirstName, char* newLastName, int newID, float newGPA);
  ~Student();
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
 private:
  char* firstName;
  char* lastName;
  int ID;
  float GPA;
};

#endif
