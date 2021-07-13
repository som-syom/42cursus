#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
	private:
		std::string	name;
	public:
		Victim(std::string name);
		~Victim();
		Victim(Victim const&);
		Victim& operator=(Victim const&);

		std::string getName();
		void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &out, Victim &v);

#endif
