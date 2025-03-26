#include "RPN.hpp"

int main(int argc, char **argv)
{
	try 
	{
		if (argc != 2)
			throw std::invalid_argument("usage: ./rpn \"3 4 +\"");
		RPN rpn(argv[1]);
	}
	catch (std::exception &e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}