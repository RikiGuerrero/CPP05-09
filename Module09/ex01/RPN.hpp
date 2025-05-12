#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <climits>
#include <cstdlib>


class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		RPN(const char *str);
};

#endif
