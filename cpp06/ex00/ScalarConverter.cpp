#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy)
{
    (void)copy;
    return(*this);
}

void	ScalarConverter::convert(std::string& s)
{
	if (!s.empty())
		castToTypes(s);
	else
		std::cerr << "Empty argument!" << std::endl;
}