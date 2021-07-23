#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _idea[100];
	public:
		Brain();
		~Brain();
		Brain(Brain const&);
		Brain& operator=(Brain const&);

		void setIdea(int, std::string const&);
		std::string getIdea(int);
};

#endif
