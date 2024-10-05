#include "Dog.hpp"

Dog::Dog() : Animal("Dog") , _brain(new Brain())
{
	cout << "I thought I saw a Dog." << endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) , _brain(new Brain(*copy._brain))
{
	cout << "I'm pretty sure I saw a Dog." << endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		delete _brain;
		_brain = new Brain(*copy._brain);
		Animal::operator=(copy);
	}
	return *this;
}

void Dog::makeSound() const
{
	cout << "Woof!" << endl;
}

Dog::~Dog()
{
	delete _brain;
	cout << "Dog is Dead" << endl;
}
