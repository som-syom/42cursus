#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <list>
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() {}
		virtual ~MutantStack() {}
		MutantStack(MutantStack const& origin) : std::stack<T, Container>(origin) {}
		MutantStack& operator=(MutantStack const& origin) {
			if (this != &origin)
				this->c = origin.c;
			return (*this);
		}

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
};

#endif
