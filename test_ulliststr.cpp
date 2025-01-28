#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr test;
  test.push_back("0");
  test.push_back("1");
  test.push_back("2");
  test.push_back("3");
  test.push_back("4");
  test.push_back("5");
  test.push_back("6");
  test.push_back("7");
  test.push_back("8");
  test.push_back("9");
  test.push_back("a");
  test.push_back("b");
                
  test.print();

  cout << "front is: " << test.front() << endl;
  cout << "back is: "<< test.back() << endl;

  
  test.print();

  return 0;
}
