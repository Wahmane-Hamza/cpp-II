#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Syntax: ./convert <literal string>" << std::endl;
		return (1);
	}
	std::string s = std::string(argv[1]);
	ScalarConverter::convert(s);
}
