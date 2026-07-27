
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <cctype>
#include <cstdlib>

#include <map>
#include <utility>
#include <algorithm>

#include <iomanip>

class NoInputFile : public std::exception
{
	public :
		const char*	what() const throw();
};

class CannotOpenFile : public std::exception
{
	public :
		const char*	what() const throw();
};

class NoHeaderFound : public std::exception
{
	public :
		const char*	what() const throw();
};

bool	parseBtcDatabase(const std::string& filePath, std::map<std::string, double>& data);
void	bitcoinExchange(const std::string& filePath, const std::map<std::string, double>& database);
