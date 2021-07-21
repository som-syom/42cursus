#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* b;
	public:
		Cat();
		~Cat();
		Cat(Cat const&);
		Cat& operator=(Cat const&);

		void makeSound() const;

};

#endif
