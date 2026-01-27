#pragma once 

#include "AForm.hpp"
#include "iostream"
#include "fstream"


class ShrubberyCreationForm :public AForm
{
    private:
		std::string	_target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &copy);

        void executeAction() const;
};
