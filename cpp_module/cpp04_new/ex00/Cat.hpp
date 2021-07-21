#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat();
		~Cat();
		Cat(Cat const&);
		Cat& operator=(Cat const&);

		void makeSound() const;

};

#endif
