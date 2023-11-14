#pragma once
#include "PostfixCalculator.h"
#include <iostream>
#include "DataStructures.h"
#include "PostfixCalculatorExceptions.h"

namespace PostfixCalculator
{
   void evaluateExpression(std::istream &in, std::ostream &out, DataStructures::LinkedStack<double> &stack, char &current)
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

   void evaluateOpr(std::ostream &out, DataStructures::LinkedStack<double> &stack, char &current)
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
}