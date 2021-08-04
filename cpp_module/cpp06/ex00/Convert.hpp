#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <sstream>

class Convert
{
	private:
		std::string	_input;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		Convert();
	public:
		Convert(std::string const&);
		virtual ~Convert();
		Convert(Convert const&);
		Convert& operator=(Convert const&);

		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
		void printAll();

};

#endif
