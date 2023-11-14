#include "UI.h"
#include <iostream>
#include <sstream>

namespace UI {
   std::string getPostfixExpression()
   {
      std::string s;
      std::cout << "Type a postfix expression! Make sure it finishes in [=]." << "\n";
      while(!(std::cin >> s))
      {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Invalid Input!" << "\n";
         std::cout << "Type a postfix expression! Make sure it finishes in [=]." << "\n";
      }
      return s;
   }

   void showResult(const std::string& out)
   {
      std::cout << out << "\n";
   }
}