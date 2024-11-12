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

	// Bellek temizleme (oluşturulan formları serbest bırak)
	delete shrubberyForm;
	delete robotomyForm;
	delete pardonForm;

	return 0;
}

