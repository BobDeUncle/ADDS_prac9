#include "Operation.h"

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

string convert(string operator1, string operand1, string operand2) {
  return operand1 + " " + operator1 + " " + operand2;
}

int calculate(string operator1, string operand1, string operand2) {
  if (operator1 == "+") {
    return stoi(operand1) + stoi(operand2);
  } else if (operator1 == "-") {
    return stoi(operand1) - stoi(operand2);
  } else if (operator1 == "/") {
    return stoi(operand1) / stoi(operand2);
  } else if (operator1 == "*") {
    return stoi(operand1) * stoi(operand2);
  }
  return 0;
}

int calculate(string operator1, string operand1, int operand2) {
  if (operator1 == "+") {
    return stoi(operand1) + operand2;
  } else if (operator1 == "-") {
    return stoi(operand1) - operand2;
  } else if (operator1 == "/") {
    return stoi(operand1) / operand2;
  } else if (operator1 == "*") {
    return stoi(operand1) * operand2;
  }
  return 0;
}

string Operation::toInfix(std::vector<std::string> inputVector) {
  bool validInput = true; 
  int lastOperator = 0;
  string output = "";

  if (inputVector.size() == 0) validInput = false;

  while (validInput == true) {
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

    if (!validInput) break;

    vector<string> operators;
    vector<string> operands;

    for (int i = 0; i <= lastOperator; i++) {
      operators.push_back(inputVector.at(i));
    }

    for (int i = lastOperator + 1; i < inputVector.size(); i++) {
      operands.push_back(inputVector.at(i));
    }

    if (!(operands.size() == operators.size() + 1)) validInput = false;
    if (!validInput) break;

    int calculatedOutput = 0;
    for (int i = 0; i < operators.size(); i++) {
      if (i == 0) {
        output = convert(operators.at(operators.size() - 1), operands.at(0), operands.at(1));
        calculatedOutput = calculate(operators.at(operators.size() - 1), operands.at(0), operands.at(1));
      } else {
        output = convert(operators.at(operators.size() - 1 - i), output, operands.at(i + 1));
        calculatedOutput = calculate(operators.at(operators.size() - 1 - i), operands.at(i + 1), calculatedOutput);
      }
      if (i < operators.size() - 1) {
        output = "(" + output + ")";
      } 
    }
    output = output + " = " + to_string(calculatedOutput);
    validInput = false;
  }

  if (output == "") {
    output = "Error";
  }

  return output;
};