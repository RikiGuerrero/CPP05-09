#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	exchange = other.exchange;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDatabase(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw std::string("could not open database file");
	std::string line, date;
	float rate;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && ss >> rate)
			exchange[date] = rate;
	}
}



std::string intToString(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

std::string formatNumber(int n)
{
	if (n < 10)
		return "0" + intToString(n);
	return intToString(n);
}

float BitcoinExchange::getExchangeRate(int year, int month, int day)
{
	std::string date = intToString(year) + "-" + formatNumber(month) + "-" + formatNumber(day);
	std::map<std::string, float>::iterator it = exchange.lower_bound(date);

	if (it == exchange.end() || it ->first != date)
	{
		if (it == exchange.begin())
			return 0;
		it--;
	}
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
	int year, month, day;
	float value;
	float rate;

	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::string("could not open input file");
	std::string line;
	getline(file, line);
	line.erase(line.find_last_not_of(" \n\r\t") + 1);
	if (line != "date | value")
		throw std::string("invalid input file format");
	while (getline(file, line))
	{
		if(line.empty())
		{
			std::cerr << "Error: empty line" << std::endl;
			continue;
		}
		else if(line.length() < 14)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		else if ((sscanf(line.c_str(), "%d-%d-%d | %f", &year, &month, &day, &value)) == 4)
		{
			try
			{
				checkValue(value);
				checkDate(year, month, day);
			}
			catch (std::string &e)
			{
				std::cerr << "Error: " << e << std::endl;
				continue;
			}
			rate = getExchangeRate(year, month, day);
			printResult(year, month, day, value, rate);
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void BitcoinExchange::checkDate(int year, int month, int day)
{
	if (year < 0 || year > 2025)
		throw std::string("invalid year");
	if (month < 1 || month > 12)
		throw std::string("invalid month");
	
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[2] = 29;

	if (day < 1 || day > daysInMonth[month])
		throw std::string("invalid day");
}

void BitcoinExchange::checkValue(float value)
{
	if (value < 0)
		throw std::string("not a positive number.");
	else if (value > 1000)
		throw std::string("too large a number.");
}

void BitcoinExchange::printResult(int year, int month, int day, float value, float rate)
{
	std::cout << year << "-"
		<< formatNumber(month) << "-"
		<< formatNumber(day) << " => "
		<< value << " = "
		<< value * rate << std::endl;
}

