#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
	protected:
		std::string	name;
	public:
		Victim();
		Victim(std::string name);
		virtual ~Victim();
		Victim(Victim const&);
		Victim& operator=(Victim const&);

		std::string getName();
		void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &out, Victim &v);

#endif
