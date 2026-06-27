#pragma once

#include <iostream>
#include <stack>
#include <vector>

template <typename T, typename Container = std::vector<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename std::stack<T, Container>::container_type::iterator			iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator	const_iterator;

	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack&	operator=(const MutantStack& copy);
		~MutantStack();

		iterator			begin();
		iterator			end();
		const_iterator		begin() const;
		const_iterator		end() const;
};

#include "MutantStack.tpp"