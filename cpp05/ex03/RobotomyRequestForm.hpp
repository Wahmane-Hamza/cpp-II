#pragma once 

#include "AForm.hpp"
#include "iostream"
#include "fstream"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
		std::string	_target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator = (const RobotomyRequestForm &copy);

        void executeAction() const;
};
