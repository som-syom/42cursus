#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>
# include <string>

typedef struct Data
{
	int			i;
	char		c;
	std::string	s;
	double		d;
}				Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t);

#endif