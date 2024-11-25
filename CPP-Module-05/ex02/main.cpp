#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat highRank("Alice", 1);
		Bureaucrat lowRank("Bob", 150);

		ShrubberyCreationForm shrubbery("Home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Zaphod");

		std::cout << shrubbery << "\n" << std::endl;
		std::cout << robotomy << "\n" << std::endl;
		std::cout << pardon << "\n" << std::endl;

		std::cout << "\n-- Formları İmzalama --" << std::endl;
		lowRank.signForm(shrubbery);
		highRank.signForm(shrubbery);
		highRank.signForm(robotomy);
		highRank.signForm(pardon);
		highRank.signForm(pardon);
		std::cout << std::endl;
		std::cout << shrubbery << "\n" << std::endl;
		std::cout << robotomy << "\n" << std::endl;
		std::cout << pardon << "\n" << std::endl;

		std::cout << "\n-- Formları Yürütme --" << std::endl;
		lowRank.executeForm(shrubbery);
		highRank.executeForm(shrubbery);
		highRank.executeForm(robotomy);
		highRank.executeForm(pardon);
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Hata: " << e.what() << std::endl;
	}

	return 0;
}
