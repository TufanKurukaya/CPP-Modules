#include "PresidentialPardonForm.hpp"

bool PresidentialPardonForm::GetSigned() const
{
	return _signed;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &oder) : AForm(oder), _signed(oder._signed), _name(oder._name)
{
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &oder)
{
	if (this != &oder)
	{
		AForm::operator=(oder);
		_signed = oder._signed;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const string &name) : AForm(name, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (_signed == false)
		throw FormNotSignedException();
	cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << endl;
}