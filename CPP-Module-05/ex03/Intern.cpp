#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &oder)
{
	*this = oder;
}

Intern &Intern::operator=(const Intern &oder)
{
	(void)oder;
	return *this;
}

AForm *Intern::makeForm(string formName, string target)
{
	string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && formNames[i] != formName)
		++i;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
			break;
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
			break;
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Intern couldn't find the form: " << formName << std::endl;
			break;
	}
	return NULL;
}

Intern::~Intern()
{
}

