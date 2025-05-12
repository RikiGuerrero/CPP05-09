#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

RPN::RPN(const char *str)
{
	std::stringstream ss(str);
	std::string token;

	while(ss >> token)
	{
		if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
		{
			int num;
			std::stringstream numStream(token);
			numStream >> num;
			_stack.push(num);
		}
		else
		{
			if (_stack.size() < 2)
				throw std::invalid_argument("Invalid RPN expression");
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			if (token == "+")
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(b - a);
			else if (token == "*")
				_stack.push(a * b);
			else if (token == "/")
			{
				if (a == 0)
					throw std::invalid_argument("Division by zero");
				_stack.push(b / a);
			}
			else
				throw std::invalid_argument("Invalid RPN expression");
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Invalid expression");
	std::cout << _stack.top() << std::endl;
}


