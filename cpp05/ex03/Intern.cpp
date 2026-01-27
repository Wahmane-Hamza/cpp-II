#include "Intern.hpp"
#include "Bureaucrat.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern&  Intern::operator = (const Intern &copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern(void){}

const char*	Intern::FormDosentExistExeption::what() const throw()
{
	return "Form Dosent Exist";
}


static AForm*	createSCF(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRRF(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createPPF(std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*	form;
	std::string	types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(std::string&) = {
		&createSCF,
		&createRRF,
		&createPPF,
	};
	int	formsNum = sizeof(types) / sizeof(types[0]);
	for (int i = 0; i < formsNum; i++)
	{
		if (types[i] == name)
		{
			form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl; 	
			return (form);
		}
	}
	throw FormDosentExistExeption();
	return (NULL);
}
