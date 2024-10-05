#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	cout << "I thought I saw a cat." << endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	cout << "I'm pretty sure I saw a cat." << endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this == &copy)
		return *this;
	Animal::operator=(copy);
	return *this;
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}

Cat::~Cat()
{
	cout << "Cat is Dead" << endl;
}
