#ifndef OPERATION_H
#define OPERATION_H

#include <stdlib.h>
#include <string>

class Operation {
  public: 
    std::string toInfix(std::vector<std::string> inputVector);
};

#endif