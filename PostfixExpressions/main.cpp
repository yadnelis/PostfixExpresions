#pragma once*
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "DataStructures.h"
#include "PostfixCalculator.h"


using namespace std;
using namespace DataStructures;
using namespace PostfixCalculator;


int main()
{
   char current;
   LinkedStack<double> stack;
   std::istringstream in("#3#4+#5*=");
   std::ostringstream out;
   try
   {
      std::cout << in.str();
      evaluateExpression(in, out, stack, current);
      std::cout << out.str();
      return 0;
   }
   catch (exception e)
   {
      in.clear();
      std::cerr << e.what();
      return -1;
   }
}


