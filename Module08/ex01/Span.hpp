#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span
{
	private:
		unsigned int _max;
		std::vector<int> _v;
	
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan();
		int longestSpan();

		class SpanIsFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class SpanIsTooShortException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif