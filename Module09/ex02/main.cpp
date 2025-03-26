#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Usage: ./ex02 \"<int1> <int2> <int3> ...\"");

		PmergeMe sorter;
		sorter.initialize(argc, argv);

		std::clock_t startVec = std::clock();
		sorter.fordJohnsonSortVector();
		std::clock_t endVec = std::clock();
		double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

		std::clock_t startDeque = std::clock();
		sorter.fordJohnsonSortDeque();
		std::clock_t endDeque = std::clock();
		double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

		sorter.printResult(argc, argv);
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << timeDeque << " us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}