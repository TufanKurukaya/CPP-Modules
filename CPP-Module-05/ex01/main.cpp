#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		try
		{
			Form form("Form", 1, 1);
			Bureaucrat bob("Bob", 2);
			bob.signForm(form);
			bob.incrementGrade();
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << endl;
	{
		try
		{
			Form form("Form", 1, 1);
			Bureaucrat bob("Bob", 1);
			bob.signForm(form);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << endl;
	{
		try
		{
			Form form("Form", 150, 1);
			Bureaucrat bob("Bob", 150);
			bob.signForm(form);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}


}
