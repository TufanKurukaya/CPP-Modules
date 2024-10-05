#include "Animal.hpp"

Animal::Animal() : _type("")
{
	cout << "Animal constructor called" << endl;
}

Animal::Animal(string type) : _type(type)
{
	cout << "Animal " << type << " is born" << endl;
}

Animal::Animal(const Animal &copy)
{
	cout << "Animal copy constructor called" << endl;
	setType(copy._type);
}

Animal &Animal::operator=(const Animal &copy)
{
	if (this == &copy)
		return *this;
	setType(copy._type);
	return *this;
}

void Animal::setType(string type)
{
	_type = type;
}

const string &Animal::getType(void) const
{
	return _type;
}

Animal::~Animal()
{
	cout << "Animal " << _type << " is Dead!" << endl;
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound!" << std::endl;
}
