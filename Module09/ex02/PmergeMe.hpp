#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void initialize(int argc, char **argv);
		void fordJohnsonSortVector();
		void fordJohnsonSortDeque();
		void printResult(int argc, char **argv);
};

#endif