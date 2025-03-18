#include "Span.hpp"

int main()
{
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;

		//sp.addNumber(1);

		Span sp2(10000);
		std::vector<int> v;
		std::srand(time(NULL));
		for (int i = 0; i < 10000; i++)
			sp2.addNumber(rand() % 100000);
		sp2.addNumber(v.begin(), v.end());
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}