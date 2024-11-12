#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;

	// Geçerli formlar
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Backyard");
		AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

		// Geçersiz form
		shrubberyForm->beSigned(b1);
		robotomyForm->beSigned(b1);
		pardonForm->beSigned(b1);

		shrubberyForm->execute(b1);
		robotomyForm->execute(b1);
		pardonForm->execute(b1);

		AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Nowhere");
		if (invalidForm)
		{
			cout << "Invalid form is not NULL" << endl;
			delete invalidForm;
		}
		// Bellek temizleme (oluşturulan formları serbest bırak)
		delete shrubberyForm;
		delete robotomyForm;
		delete pardonForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}

