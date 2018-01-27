/*
  Author: Aryan Gupta
  Date: 12/16/17
  This program allows a user to create a student list and uses a linked list to store and manage the data
 */

#include "Node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

// method prototypes
void addNode(Student* student, Node* &currentNode);
void deleteNode(Node* &head, int ID);
void printList(Node* next);
void average(Node* currentNode);

// main method 
int main() {

  Node* head = NULL;
  
  //instructions
  cout << "\n";
  cout << "---------------------------------------------------------" << endl;
  cout << "| To create a student list use the following commands   |" << endl;
  cout << "| Type (ADD) to create a new entry for a student        |" << endl;
  cout << "| Type (DELETE) to remove a student from the list       |" << endl;
  cout << "| Type (PRINT) to print all the students in the list    |" << endl;
  cout << "| Type (AVERAGE) to see the average GPA of all students |" << endl;
  cout << "| Type (QUIT) whenever you are done or want to leave    |" << endl;
  cout << "| **NOTE** Type all commands WITHOUT the parentheses () |" << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << "\n";
  cout << "\n";
  cout << "\n";
  cout << "---------------------------------------------------------" << endl;
  
  // keep running till user wants to quit
  bool quit = false;
  while(quit == false) {

    // holds the users input
    char command[1000];

    // all the information need for a new student's entry
    char* firstName = new char[50];
    char* lastName = new char[50];
    int ID;
    float GPA;
    
    cout << "Type one of the commands listed above: ";
    cin.getline(command, 1000);
    cout << "\n";
    
    // if user wants to add a student
    if(strcmp(command, "ADD") == 0) {
      cout << "---New student entry---" << endl;

      // enter the information  
      cout << "Enter the student's first name: ";
      cin.getline(firstName, 50);
      cout << "Enter the student's last name: ";
      cin.getline(lastName, 50);
      cout << "Enter the student's 6 digit ID #: ";
      cin >> ID;
      cin.get();
      cout << "Enter the student's GPA: ";
      cin >> GPA;
      cin.get();

      // adds the new student entry to the list
      Student* student = new Student(firstName, lastName, ID, GPA);
      addNode(student, head);
      
      cout << "---------------------------------------------------------" << endl;
    }
    // if user wants to remove a student
    else if (strcmp(command, "DELETE") == 0) {
      cout << "Enter the ID of the student you want to delete: ";
      cin >> ID;
      cin.get();
      deleteNode(head, ID);
      cout << "Student deleted." << endl;
      cout << "---------------------------------------------------------" << endl;
    }
    // if user wants to see all the students currently stored in the list
    else if (strcmp(command, "PRINT") == 0) {
      cout << "---Printing all students in the list---" << endl;
      printList(head);
      cout << "---------------------------------------------------------" << endl;
    }
    // if user wants to see the average of all the students GPA's
    else if (strcmp(command, "AVERAGE") == 0) {
      cout << "Averaging all GPA's" << endl;
      average(head);
      cout << "---------------------------------------------------------" << endl;
    }
    // if user wants to quit the program
    else if (strcmp(command, "QUIT") == 0) {
      cout << "Terminating program" << endl;
      cout << "---------------------------------------------------------" << endl;
      quit = true;
    }
    // the user entered an invalid command
    else {    
      cout << "Invalid command, try again. ";
    }
  }
}

// methods


/* 
   adds a node with all the students information
   orders the nodes from least to greatest id #
*/
void addNode(Student* student, Node* &currentNode) {
  if(currentNode != NULL) {
    Node* next = currentNode->getNext();
    if(currentNode->getNext() != NULL) {
      // if the new student's ID # is between currentNode and next
      if(currentNode->getStudent()->getID() < student->getID() && currentNode->getNext()->getStudent()->getID() > student->getID()) {
	Node* temp = currentNode->getNext();
	// adds temp node between currentNode and next
	currentNode->setNext(new Node(student));
	next = currentNode->getNext();
	next->setNext(temp);
	return;
      }
      // if the new student's ID # is less than head nodes
      if(student->getID() < currentNode->getStudent()->getID()) {
	Node* temp = currentNode;
	// adds the new node for the new student before currentNode
	currentNode = new Node(student);
	currentNode->setNext(temp);
	return;
      }
    }
    else {
      // if this is the last node in the list, add the new node at the end
      currentNode->setNext(new Node(student));
      return;
    }
  }
  else {
    // if this is the first node in the list, head is equal to this
    Node* temp = currentNode;
    currentNode = new Node(student);
    currentNode->setNext(temp);
    return;
  }
  // recursively calls addNode on the next node
  Node* next = currentNode->getNext();
  addNode(student, next);
}

// deletes a Node by a student's ID #
void deleteNode(Node* &head, int ID) {
  Node* currentNode = head;
  Node* previousNode = NULL;
  /* 
   goes through the list to find the specified node
   and deletes it then takes it the previous nod
   and makes it point to the node that was after the one 
   that was removed
  */
  while (currentNode != NULL) {
    // if the specified ID is found
    if( currentNode->getStudent()->getID() == ID) {
      // check if this ISN'T the first node in the list
      if (previousNode != NULL) {
	// if it ISN'T, set the previous node so its pointing to the node after the deleted one
	previousNode->setNext(currentNode->getNext());
      }
      // if this IS the first node in the list
      else {
	// check to see if there is a node after this one
	if (head->getNext() != NULL) {
	  // if there is make it point to the next node
	  head = head->getNext();
	}
	// there is only one node in the list at this point
	else {
	  // make head point to NULL then
	  head = NULL;
	}
      }

      previousNode = currentNode;
      currentNode = currentNode->getNext();
      // now delete the student
      delete(currentNode);
      return;
    }
    //else {
      /* 
	 make the previous node point to current and make current point to the node
	 that is after the one that got deleted
      */
      //previousNode = currentNode;
      //currentNode = currentNode->getNext();
      //}
  }
  // at this point the student is not in the list
  cout << "Student is not in the list" << endl;
}

// goes through the entire list and prints out all the student and their respective information
void printList(Node* next) {
  // print only to 2 decimal places for gpa
  cout.setf(ios::fixed);
  cout.precision(2);
  if(next != NULL) {
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() <<
      ", ID#: " << next->getStudent()->getID() << ", GPA: " << next->getStudent()->getGPA() << endl;
    // calls printList recursively
    printList(next->getNext());
  }
}

void average(Node* currentNode) {
  cout.setf(ios::fixed);
  cout.precision(2);
  float total = 0;
  int counter = 0;
  while(currentNode != NULL) {
    // add all the students GPAs and keep track of # of students in list
    total = total + currentNode->getStudent()->getGPA();
    counter += 1;
    currentNode = currentNode->getNext();
  }
  // print out GPA
  cout << "Average GPA across all the students: " << total/counter << endl;
}
