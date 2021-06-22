#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Human
{
	private:
		const Brain b;
	public:
		Human();
		~Human();
		const Brain	*identify() const;
		const Brain	&getBrain() const;
};

#endif