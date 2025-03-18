#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef std::stack<T> stack;
		typedef typename stack::container_type container;
		typedef typename container::iterator iterator;

		MutantStack() : stack() {}

		MutantStack(const MutantStack &other) : stack(other) {}

		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return *this;
			stack::operator=(other);
			return *this;
		}

		~MutantStack() {}

		iterator begin()
		{
			return stack::c.begin();
		}

		iterator end()
		{
			return stack::c.end();
		}
};

#endif