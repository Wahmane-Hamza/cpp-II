#include "iter.hpp"

template <typename X>
void	print(X item)
{
	std::cout << item << std::endl;
}

int main()
{
	int						arr1[2] = {3, 10};
	const std::string		arr2[] = {"Hello", "World"};
	
	iter(arr1, 2, &print<int>);
	iter(arr2, 2, &print<std::string>);
}
