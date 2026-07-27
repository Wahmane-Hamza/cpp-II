#include "BitcoinExchange.hpp"

#include <vector>
#include <algorithm>

int	main(int argc, char *argv[])
{
	try
	{
		std::map<std::string, double> data;

		if (argc != 2)
		{
			throw CannotOpenFile();
		}
		parseBtcDatabase("data.csv", data);
		bitcoinExchange(argv[1], data);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
