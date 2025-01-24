/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void deleteList(Node * list) //from grade_split.cpp
{
	Node * currElement = list;

	while(currElement != nullptr)
	{
		Node * nextElement = currElement->next;

		delete currElement;

		currElement = nextElement;
	}
}

int main(int argc, char* argv[])
{
  Node* oddnums = nullptr;
  Node* evennums = nullptr;
  Node* input = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))));

  Node* temp3 = input;
  cout << "input is: ";
  while (temp3 != nullptr)
  {
    cout << temp3->value << " ";
    temp3 = temp3->next;
  } 

  Node* temp1 = oddnums;
  cout << "odds are: ";
  while (temp1 != nullptr)
  {
    cout << temp1->value << " ";
    temp1 = temp1->next;
  }

  Node* temp2 = evennums;
  cout << "evens are: ";
  while (temp2 != nullptr)
  {
    cout << temp2->value << " ";
    temp2 = temp2->next;
  }

  split(input, oddnums, evennums);

  cout << endl;
  cout << "results" << endl;
  temp3 = input;
  cout << "input is: ";
  while (temp3 != nullptr)
  {
    cout << temp3->value << " ";
    temp3 = temp3->next;
  } 

  temp1 = oddnums;
  cout << "odds are: ";
  while (temp1 != nullptr)
  {
    cout << temp1->value << " ";
    temp1 = temp1->next;
  }

  temp2 = evennums;
  cout << "evens are: ";
  while (temp2 != nullptr)
  {
    cout << temp2->value << " ";
    temp2 = temp2->next;
  }

  deleteList(oddnums);
  deleteList(evennums);

  return 0;
}
