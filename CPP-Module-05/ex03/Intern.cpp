#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm *Intern::MakeShrubberyCreationForm(string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::MakeRobotomyRequestForm(string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::MakePresidentialPardonForm(string target)
{
	return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(string formName, string target)
{
	string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*f[])(string) = {
		&Intern::MakePresidentialPardonForm,
		&Intern::MakeRobotomyRequestForm,
		&Intern::MakeShrubberyCreationForm
	};
	int i = 0;
	while (i < 3 && formNames[i] != formName)
		i++;
	if (i < 3)
		return (this->*f[i])(target);
	std::cout << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}



