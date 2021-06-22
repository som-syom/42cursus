#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
private:
	std::string address;
public:
	Brain();
	~Brain();
	const Brain	*identify() const;
};

#endif