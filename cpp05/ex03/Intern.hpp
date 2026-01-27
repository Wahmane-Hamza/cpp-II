#pragma once 

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
		std::string	_target;
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern &operator = (const Intern &copy);

        class FormDosentExistExeption : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		AForm*	makeForm(std::string name, std::string target);
};
