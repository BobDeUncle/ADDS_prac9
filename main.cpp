#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include "Operation.h"

using namespace std;

int main() {
  string input;
  getline(cin, input);

  std::string bufferString;
  std::stringstream ss(input);
  std::vector<std::string> inputVector;

  while (ss >> bufferString) {
    inputVector.push_back(bufferString);
  }

  Operation operation; 
  string output = operation.toInfix(inputVector);\
  cout << output << endl; 
}