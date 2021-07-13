#ifndef SOM_HPP
# define SOM_HPP

# include "Victim.hpp"

class Som : public Victim
{
	private:
		
	public:
		Som(std::string);
		~Som();
		Som(Som const&);
		Som& operator=(Som const&);

		void getPolymorphed() const;
};

#endif
