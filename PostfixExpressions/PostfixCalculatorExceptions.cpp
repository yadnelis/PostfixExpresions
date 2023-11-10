#include "PostfixCalculatorExceptions.h"

DivisionByCeroException::DivisionByCeroException(): logic_error("Cannot divide by cero.")
{}
DivisionByCeroException::DivisionByCeroException(char const *const message): logic_error(message)
{}


InvalidOperatorException::InvalidOperatorException(): logic_error("Invalid operator for postfix expresion.")
{}
InvalidOperatorException::InvalidOperatorException(char const *const message): logic_error(message)
{}


InsuficientOperands::InsuficientOperands(): logic_error("Insificient operands for postfix expresion.")
{}
InsuficientOperands::InsuficientOperands(char const *const message): logic_error(message)
{}