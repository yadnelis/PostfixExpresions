#pragma once
#include <iostream>
#include "DataStructures.h"

namespace PostfixCalculator
{
   void evaluateExpression(std::istream &in, std::ostream &out, DataStructures::LinkedStack<double> &stack, char &current);
}