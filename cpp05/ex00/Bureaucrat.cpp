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


Bureaucrat::Bureaucrat(void): name("unkown"), grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->checkGrade(grade);
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat&  Bureaucrat::operator = (const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->grade = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::increGrade()
{
	this->checkGrade(this->grade - 1);
	this->grade--;
}

void	Bureaucrat::decreGrade()
{
	this->checkGrade(this->grade + 1);
	this->grade++;
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

std::ostream&	operator<<(std::ostream& cout, const Bureaucrat& obj)
{
	cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return cout;
}
