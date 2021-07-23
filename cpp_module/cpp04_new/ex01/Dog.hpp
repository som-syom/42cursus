#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* b;
	public:
		Dog();
		~Dog();
		Dog(Dog const&);
		Dog& operator=(Dog const&);

		void makeSound() const;
		void setIdea(int, std::string const&);
		std::string getIdea(int);
};

#endif
