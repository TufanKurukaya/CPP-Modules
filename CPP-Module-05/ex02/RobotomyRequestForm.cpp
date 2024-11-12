#include "RobotomyRequestForm.hpp"
#include <cstdlib>
bool RobotomyRequestForm::GetSigned() const
{
	return _signed;
}
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const string &name) : AForm(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oder) : AForm(oder), _signed(oder._signed), _name(oder._name)
{
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &oder)
{
	if (this != &oder)
	{
		AForm::operator=(oder);
		_signed = oder._signed;
	}
	return *this;
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
	cout << executor.getName() << (success ? " could not be robotized" : " was successfully robotized") << endl;
}
