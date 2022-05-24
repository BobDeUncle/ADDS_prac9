#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>

using namespace std;

bool isValidOperand(string input) {
  vector<char> v(input.begin(), input.end());
  if (v.size() < 1 || v.size() > 2) {
    return false; 
  }
  for (int i = 0; i < v.size(); i++) {
    if (char(v.at(i)) - '0' < 0 || char(v.at(i)) - '0' > 9) {
      return false;
    }
  }
  return true;
}

bool isValidOperator(string input) {
  vector<char> v(input.begin(), input.end());
  if (v.size() != 1) {
    return false;
  } else if (v.at(0) != '+' && v.at(0) != '-' && v.at(0) != '/' && v.at(0) != '*') {
    return false;
  }
  return true; 
}

int main() {
  string input;
  getline(cin, input);

  std::string bufferString;
  std::stringstream ss(input);
  std::vector<std::string> inputVector;

  while (ss >> bufferString) {
    inputVector.push_back(bufferString);
  }

  // input.erase(remove(input.begin(), input.end(), ' '), input.end());
  // vector<int> inputVector(input.begin(), input.end());

  int validInput = true; 
  int lastOperator = 0;

  for (int i = 0; i < inputVector.size(); i++) {
    if (!isValidOperator(inputVector.at(i))) {
      lastOperator = i - 1;
      break;
    }
  }

  for (int i = lastOperator + 1; i < inputVector.size(); i++) {
    if (!isValidOperand(inputVector.at(i))) {
      validInput = false;
      break;
    }
  }

  vector<string> operators;
  vector<string> operands;

  for (int i = 0; i <= lastOperator; i++) {
    operators.push_back(inputVector.at(i));
  }

  for (int i = lastOperator + 1; i < inputVector.size(); i++) {
    operands.push_back(inputVector.at(i));
  }

  cout << operators.size() << ' ' << operands.size() << endl;

  if (!(operands.size() == operators.size() + 1)) {
    validInput = false;
  }

  if (!validInput) {
    cout << "Error" << endl;
  } else {
    cout << "Nice" << endl; 
  }

}