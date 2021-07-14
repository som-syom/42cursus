#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>
# include <string>

class SuperMutant
{
	private:
		
	public:
		SuperMutant();
		~SuperMutant();
		SuperMutant(SuperMutant const&);
		SuperMutant& operator=(SuperMutant const&);

};

#endif
