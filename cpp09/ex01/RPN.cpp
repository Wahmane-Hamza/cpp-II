#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& copy){*this=copy;}

RPN& RPN::operator=(const RPN& copy)
{
  if (this == &copy)
    return *this;
  return *this;
}

int RPN::calcule(const char* exp)
{
    int result;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (std::isspace(exp[i]))
            continue;

        if (exp[i] >= '0' && exp[i] <= '9')
        {
            _container.push(exp[i] - '0');

            if (exp[i + 1] != '\0' && !std::isspace(exp[i + 1]))
                throw RPNException("accept one digit as number (0-9)");

            continue;
        }

        if (_container.size() < 2)
            throw RPNException("invalid expression");

        int a = _container.top();
        _container.pop();

        int b = _container.top();
        _container.pop();

        switch (exp[i])
        {
            case '+':
                result = b + a;
                break;

            case '-':
                result = b - a;
                break;

            case '*':
                result = b * a;
                break;

            case '/':
                if (a == 0)
                    throw RPNException("math error: can't divide by 0");

                result = b / a;
                break;

            default:
                throw RPNException("operator not found");
        }

        _container.push(result);
    }

    if (_container.empty())
        throw RPNException("empty expression");

    if (_container.size() != 1)
        throw RPNException(
            "stack has more than one number at the end of calculation"
        );

    result = _container.top();
    _container.pop();

    return result;
}

RPN::RPNException::RPNException(std::string msg): _msg(msg){}
RPN::RPNException::~RPNException() throw(){}
const char* RPN::RPNException::what() const throw() {return _msg.c_str();}
