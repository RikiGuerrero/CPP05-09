#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) 
{ 
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::initialize(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream readstring(argv[i]);
		int num;
		if (!(readstring >> num) || !(readstring.eof()))
			throw std::invalid_argument("Invalid argument: " + std::string(argv[i]));
		if (num < 0)
			throw std::invalid_argument("Negative number: " + std::string(argv[i]));
		_vec.push_back(num);
		_deque.push_back(num);
	}
}

void PmergeMe::fordJohnsonSortVector()
{
	if (_vec.size() <= 1)
		return;

	std::vector<int> mainList;
	std::vector<int> subList;

	for (size_t i = 0; i < _vec.size(); i += 2)
	{
		if (i + 1 < _vec.size())
		{
			if (_vec[i] > _vec[i + 1])
			{
				mainList.push_back(_vec[i]);
				subList.push_back(_vec[i + 1]);
			}
			else
			{
				mainList.push_back(_vec[i + 1]);
				subList.push_back(_vec[i]);
			}
		}
		else
			mainList.push_back(_vec[i]);
	}

	std::sort(mainList.begin(), mainList.end());
	for (size_t i = 0; i < subList.size(); i++)
	{
		std::vector<int>::iterator pos = std::upper_bound(mainList.begin(), mainList.end(), subList[i]);
		mainList.insert(pos, subList[i]);
	}
	_vec = mainList;
}

void PmergeMe::fordJohnsonSortDeque()
{
	if (_deque.size() <= 1)
		return;
	
	std::deque<int> mainList;
	std::deque<int> subList;

	for (size_t i = 0; i < _deque.size(); i += 2)
	{
		if (i + 1 < _deque.size())
		{
			if (_deque[i] > _deque[i + 1])
			{
				mainList.push_back(_deque[i]);
				subList.push_back(_deque[i + 1]);
			}
			else
			{
				mainList.push_back(_deque[i + 1]);
				subList.push_back(_deque[i]);
			}
		}
		else
			mainList.push_back(_deque[i]);
	}

	std::sort(mainList.begin(), mainList.end());
	for (size_t i = 0; i < subList.size(); i++)
	{
		std::deque<int>::iterator pos = std::upper_bound(mainList.begin(), mainList.end(), subList[i]);
		mainList.insert(pos, subList[i]);
	}
	_deque = mainList;
}

void PmergeMe::printResult(int argc, char **argv)
{
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}