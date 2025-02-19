#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 50);
		Bureaucrat b2("b2", 150);
		Form f1("f1", 50, 50);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}