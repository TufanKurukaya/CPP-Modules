#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;

	// Geçerli formlar
	AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Backyard");
	AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

	// Geçersiz form
	AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Nowhere");
	if (invalidForm == NULL)
		cout << "Invalid form is NULL" << endl;
	delete shrubberyForm;
	delete robotomyForm;
	delete pardonForm;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	return 0;
}
