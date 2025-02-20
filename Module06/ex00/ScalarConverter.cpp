#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

static bool isChar(const std::string &input)
{
	if (input.size() == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
		return (true);
	return (false);
}

static bool isInt(const std::string &input)
{
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);
	
	while (i < input.size())
	{
		if (!std::isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool isFloat(const std::string &input)
{
	size_t i = 0;
	bool dot = false;

	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);
	
	while (i < input.size() - 1)
	{
		if (input[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(input[i]))
			return (false);
		i++;
	}
	if (input[i] == 'f' && dot)
		return (true);
	return (false);
}

static bool isDouble(const std::string &input)
{
	size_t i = 0;
	bool dot = false;

	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);
	while (i < input.size())
	{
		if (input[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(input[i]))
			return (false);
		i++;
	}
	if (dot)
		return (true);
	return (false);
}

void ScalarConverter::convert(const std::string &input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "char: impossible\nint: impossible\n"
				  << "float: " << input << "\ndouble: " << input.substr(0, input.size() - 1) << std::endl;
		return;
	}
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "char: impossible\nint: impossible\n"
				  << "float: " << input << "f\ndouble: " << input << std::endl;
		return;
	}

	if (isChar(input))
	{
		char c = input[0];
		std::cout << "char: '" << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	if (isInt(input))
	{
		long val = strtol(input.c_str(), NULL, 10);
		if (val > std::numeric_limits<char>::max() || val < std::numeric_limits<char>::min())
		{
			std::cout << "char: impossible\nint: impossible\n"
					  << "float: impossible\ndouble: impossible" << std::endl;
			return;
		}
		int i = static_cast<int>(val);
		if (i < 32 || i > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		return;
	}

	if (isFloat(input))
	{
		float f = strtof(input.c_str(), NULL);
		if (std::isnan(f) || std::isinf(f))
			std::cout << "char: impossible\nint: impossible" << std::endl;
		else if (f < 32 || f > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
		return;
	}

	if (isDouble(input))
	{
		double d = strtod(input.c_str(), NULL);
		if (std::isnan(d) || std::isinf(d))
			std::cout << "char: impossible\nint: impossible" << std::endl;
		else if (d < 32 || d > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}
	std::cout << "Error: Invalid input" << std::endl;
}