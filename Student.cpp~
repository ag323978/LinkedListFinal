#include "Student.h"
#include <cstring>
#include <iostream>

using namespace std;

Student::Student(char* newFirstName, char* newLastName, int newID, float newGPA) {
  firstName = newFirstName;
  lastName = newLastName;
  ID = newID;
  GPA = newGPA;
}

Student::~Student() {
  delete firstName;
  delete lastName;
}

char* Student::getName() {
  return firstName;
  return lastName;
}

int Student::getID() {
  return ID;
}

float Student::getGPA() {
  return GPA;
}
