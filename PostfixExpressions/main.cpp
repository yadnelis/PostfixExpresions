#pragma once*
#include <iostream>
#include <sstream>
#include <exception>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include "DataStructures.h"
#include "PostfixCalculator.h"
#include "UI.h"


using namespace std;
using namespace DataStructures;
using namespace PostfixCalculator;


int main()
{
   char current;
   LinkedStack<double> stack;
   std::istringstream in;
   std::ostringstream out;
   std::string s;
   try
   {
      do
      {
         s = UI::getPostfixExpression();
         if(s != "quit")
         {
            in.str(s);
            evaluateExpression(in, out, stack, current);
            UI::showResult(out.str());
         }
      }
      while(s != "quit");
      return 0;
   }
   catch (exception e)
   {
      in.clear();
      std::cerr << e.what();
      return -1;
   }
}


