#pragma once

#include <iostream>

using std::string;

class Brain
{
	private:
		string _ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();
		
};
