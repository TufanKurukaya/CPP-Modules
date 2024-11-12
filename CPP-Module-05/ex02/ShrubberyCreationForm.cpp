#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &name) : AForm(name, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oder) : AForm(oder), _signed(oder._signed), _name(oder._name)
{
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oder)
{
	if (this != &oder)
	{
		AForm::operator=(oder);
		_signed = oder._signed;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

bool ShrubberyCreationForm::GetSigned() const
{
	return _signed;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (_signed == false)
		throw FormNotSignedException();
	std::ofstream file((executor.getName() + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::exception();
	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
}
