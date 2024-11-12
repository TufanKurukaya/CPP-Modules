#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cerr;
using std::endl;
using std::string;
using std::cout;

class Intern
{
	public:
		Intern();
		~Intern();
		AForm *makeForm(string formName, string target);
	private:
		AForm *MakeShrubberyCreationForm(string target);
		AForm *MakeRobotomyRequestForm(string target);
		AForm *MakePresidentialPardonForm(string target);
};


#endif
