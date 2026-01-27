#pragma once 

#include "AForm.hpp"
#include "iostream"
#include "fstream"

class PresidentialPardonForm : public AForm
{
    private:
		std::string	_target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &copy);

        void executeAction() const;
};
