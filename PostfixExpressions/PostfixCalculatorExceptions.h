#pragma once
#include <stdexcept>

class DivisionByCeroException: public std::logic_error
{
   public:
   DivisionByCeroException();
   DivisionByCeroException(char const* const message);
};

class InvalidOperatorException: public std::logic_error
{
   public:
   InvalidOperatorException();
   InvalidOperatorException(char const *const message);
};

class InsuficientOperands: public std::logic_error
{
   public:
   InsuficientOperands();
   InsuficientOperands(char const *const message);
};



