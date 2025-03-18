#include "iter.hpp"

void printint(int &i)
{
	std::cout << i << " ";
}

void printString(std::string &s)
{
	std::cout << s << " ";
}

void addOne(int &i)
{
	i += 1;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};

	std::cout << "intArray: ";
	iter(intArray, 5, printint);
	std::cout << std::endl;

	iter(intArray, 5, addOne);
	std::cout << "intArray: ";
	iter(intArray, 5, printint);
	std::cout << std::endl;

	std::string strArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "strArray: ";
	iter(strArray, 5, printString);
	std::cout << std::endl;

	return 0;
}