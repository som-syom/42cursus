#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{
	private:
		std::string	name;
		std::string	title;
	public:
		Sorcerer(std::string name, std::string title);
		~Sorcerer();
		Sorcerer(Sorcerer const&);
		Sorcerer& operator=(Sorcerer const&);

		std::string getName();
		std::string getTitle();
		void polymorph(Victim const&) const;
};

std::ostream& operator<<(std::ostream &out, Sorcerer &s);

#endif
