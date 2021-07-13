#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
	private:
		
	public:
		Peon(std::string);
		~Peon();
		Peon(Peon const&);
		Peon& operator=(Peon const&);

		void getPolymorphed() const;
};

#endif
