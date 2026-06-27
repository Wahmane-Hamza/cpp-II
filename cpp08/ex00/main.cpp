#include "easyfind.hpp"

int	main()
{

	std::vector<int>	container;
	std::vector<int>::iterator		it;
	
	container.push_back(0);
	container.push_back(2);
	container.push_back(3);

	try
	{
		std::cout << *(easyfind(container, 2)) << " is Found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << *(easyfind(container, 42)) << " is Found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
