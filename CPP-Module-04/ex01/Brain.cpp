#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created!" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this == &copy)
		return *this;
	for (size_t i = 0; i < 100; i++)
		if (!_ideas[i].empty())
			_ideas[i] = copy._ideas[i];
	return *this;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copied!" << std::endl;
	*this = copy;
}


Brain::~Brain()
{
	std::cout << "Brain destroyed!" << std::endl;
}
