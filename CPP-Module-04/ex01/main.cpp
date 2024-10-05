#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
int main()
{
	{
		cout << GREEN << "----------====EXIRCISE I====----------\n"
			 << PURPLE << endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	{
		cout << GREEN << "\n----------====EXIRCISE II====---------\n"
			 << ORANGE << endl;

		const Animal *j = new Dog();
		const Animal *i = new Cat();
		const Dog *y = new Dog();
		const Cat *x = new Cat();
		j->makeSound();
		i->makeSound();
		delete i;
		delete j;
		j = x;
		i = y;
		j->makeSound();
		i->makeSound();
		delete x;
		delete y;
	}
	{

		cout << GREEN << "\n---------====EXIRCISE III====---------\n" << ORANGE << endl;

		Dog *a = new Dog();
		Dog *b = new Dog();
	}
}
