#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &)
{
}

AForm *Intern::makeForm(string formName, string target)
{
	string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *forms[] = {
		&ShrubberyCreationForm(target),
		&RobotomyRequestForm(target),
		&PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
	}
	std::cout << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}

Intern::~Intern()
{
}

