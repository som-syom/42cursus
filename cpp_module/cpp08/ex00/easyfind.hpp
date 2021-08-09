#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return ("!! Not Found Error !!");
		}
};

template <typename T>
typename T::iterator easyfind(T& t, int i)
{
	typename T::iterator iter = std::find(t.begin(), t.end(), i);
	if (iter != t.end())
		return (iter);
	else
		throw NotFoundException();
}

#endif
