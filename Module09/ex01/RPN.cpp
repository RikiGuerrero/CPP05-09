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
	std::stack<int> stack;
	std::stringstream ss(str);
	std::string token;

	while(ss >> token)
	{
		if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
		{
			int num;
			std::stringstream numStream(token);
			numStream >> num;
			stack.push(num);
		}
		else
		{
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid RPN expression");
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(b - a);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/")
			{
				if (a == 0)
					throw std::invalid_argument("Division by zero");
				stack.push(b / a);
			}
			else
				throw std::invalid_argument("Invalid RPN expression");
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid expression");
	std::cout << stack.top() << std::endl;
}


