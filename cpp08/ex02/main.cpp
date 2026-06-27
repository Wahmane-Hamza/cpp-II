#include "MutantStack.hpp"

int	main()
{
	MutantStack<int>	s1;

	s1.push(5);
	s1.push(11);
	s1.push(85);

	s1.pop();

	MutantStack<int>	s2(s1);
	MutantStack<int>::iterator it = s2.begin();
	MutantStack<int>::iterator ite = s2.end();
	
	// *it = 1337;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	s1.pop();
	s1.pop();

	std::cout << s1.size() << std::endl;
	std::cout << s2.size() << std::endl;

	s1 = s2;
	it = s1.begin();
	ite = s1.end();
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}