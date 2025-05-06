#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "INT STACK TEST" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element of the stack: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Current size of the stack: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
/*
	std::cout << "\nINT STACK TEST WITH std::list" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top element of the list: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Current size of the list: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
*/
	std::cout << "\n\nSTRING STACK TEST" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");
	strStack.push("How");
	MutantStack<std::string>::iterator strIt = strStack.begin();
	MutantStack<std::string>::iterator strIte = strStack.end();

	++strIt;
	--strIt;
	while (strIt != strIte)
	{
		std::cout << *strIt << std::endl;
		++strIt;
	}
	return 0;
}