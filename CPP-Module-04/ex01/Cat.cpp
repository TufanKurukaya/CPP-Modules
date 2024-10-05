#include "Cat.hpp"

Cat::Cat() : Animal("Cat") , _brain(new Brain())
{
	cout << "I thought I saw a cat." << endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) , _brain(new Brain(*copy._brain))
{
	cout << "I'm pretty sure I saw a cat." << endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this == &copy)
		return *this;
	delete _brain;
	_brain = new Brain(*copy._brain);
	Animal::operator=(copy);
	return *this;
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}

Cat::~Cat()
{
	delete _brain;
	cout << "Cat is Dead" << endl;
}
