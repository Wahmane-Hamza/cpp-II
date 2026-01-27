/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:51:20 by hwahmane          #+#    #+#             */
/*   Updated: 2026/01/17 17:03:45 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("unkown"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat&  Bureaucrat::operator = (const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->_grade = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increGrade()
{
	this->checkGrade(this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::decreGrade()
{
	this->checkGrade(this->_grade + 1);
	this->_grade++;
}

void	Bureaucrat::checkGrade(int grade) const
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

void	 Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign: "  << obj.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{		
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute: "  << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& cout, const Bureaucrat& obj)
{
	cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return cout;
}
