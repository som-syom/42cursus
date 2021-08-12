#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>

class span
{
	private:
		unsigned int	_N;
	public:
		span();
		~span();
		span(span const&);
		span& operator=(span const&);

};

#endif
