#include "RobotomyRequestForm.hpp"
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const string &name) : AForm(name, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (_signed == false)
		throw FormNotSignedException();
	srand(time(NULL));
	bool success = rand() % 2;
	cout << executor.getName() << (success ? "could not be robotized" : "was successfully robotized") << endl;
}
