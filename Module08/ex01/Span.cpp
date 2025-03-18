#include "Span.hpp"

Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_max = other._max;
	_v = other._v;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v.size() >= _max)
		throw SpanIsFullException();
	_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _max)
		throw SpanIsFullException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw SpanIsTooShortException();
	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw SpanIsTooShortException();
	std::sort(_v.begin(), _v.end());
	return _v.back() - _v.front();
}

const char *Span::SpanIsFullException::what() const throw()
{
	return "Span is full";
}

const char *Span::SpanIsTooShortException::what() const throw()
{
	return "Span is too short";
}