#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	try
	{
		if (argc > 2)
			throw std::string("Too many arguments");
		BitcoinExchange exchange;
		exchange.processInputFile(argv[1]);
	}
	catch (std::string &e)
	{
		std::cerr << "Error: " << e << std::endl;
		return 1;
	}
	return 0;
}