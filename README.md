# Postfix Expressions
This CLI program evaluates *arithmetic operations* written in postfix notation.

## What is postfix notation?
Postfix notation, also called Reversed Polish notation, is a way of writing arithmetic without using parenthesis. Instead of writing the operator in between the operand, it is written after the operand.  Here are some examples :


| infix                | postfix      |
| -------------------- | ------------ |
| a + b                | ab+          |
| a + b * c            | abc\*+       |
| (a+b) \*c            | ab+c*        |
| (a-b) \* (c+d)       | ab+cd+\*     |
| (a+b) \* (c-d/e) + f | ab+cde/-\*f+ |

## Using
For this implementation, you need to write a '#' before each digit. (e.g. #a#b#c\*+ )
