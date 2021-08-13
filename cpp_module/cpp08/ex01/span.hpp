#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <set>

class Span
{
	private:
		unsigned int _size;
		std::set<int> _numbers;
		Span();
	public:
		Span(unsigned int);
		virtual ~Span();
		Span(Span const&);
		Span& operator=(Span const&);

		void addNumber(unsigned int);
		int shortestSpan();
		int longestSpan();

		class OutofRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DuplicatedNumException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotFoundNumException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NumCountOneException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif
