#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	try
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);

		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		std::cout << *easyfind(vec, 30) << std::endl;
		std::cout << *easyfind(lst, 3) << std::endl;

		std::cout << *easyfind(vec, 100) << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
}