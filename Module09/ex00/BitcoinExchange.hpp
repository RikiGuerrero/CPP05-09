#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> exchange;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDatabase(const std::string &fileName);
		void processInputFile(const std::string &inputFile);
		void checkDate(int year, int month, int day);
		void checkValue(float value);
		float getExchangeRate(int year, int month, int day);
		void printResult(int year, int month, int day, float value, float rate);
		
};

#endif