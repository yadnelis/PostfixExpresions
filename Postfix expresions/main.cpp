#pragma once*
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "DataStructures.h"
#include "PostfixCalculatorExceptions.h"


using namespace std;
using namespace DataStructures;

void evaluateExpression(istream &in, ostream &out, LinkedStack<double> &stack, char &current);
void evaluateOpr(ostream &out, LinkedStack<double> &stack,char &current);
void discardExp(istream &in, ostream &out, char &current);
void printResult(ostream &out, LinkedStack<double> &stack);

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

void evaluateExpression(istream &in, ostream &out, LinkedStack<double> &stack, char &current)
{
   double num;
   in >> current;
   while(current != '=')
   {
      if(current == '#')
      {
         in >> num;
         stack.push(num);
      }
      else
         evaluateOpr(out, stack, current);
      in >> current;
   }
   out << stack.top();
}

void evaluateOpr(ostream &out, LinkedStack<double> &stack, char &current)
{
   double op1, op2;

   if(stack.isEmptyStack())
      throw InsuficientOperands();

   op2 = stack.top();
   stack.pop();

   if(stack.isEmptyStack())
      throw InsuficientOperands();

   op1 = stack.top();
   stack.pop();

   switch(current)
   {
      case '+':
         stack.push(op1 + op2);
         break;
      case '-':
         stack.push(op1 - op2);
         break;
      case '/':
         stack.push(op1 / op2);
         break;
      case '*':
         stack.push(op1 * op2);
         break;
      default:
         throw InvalidOperatorException();
         break;
   }
}
