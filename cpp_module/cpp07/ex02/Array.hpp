#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _size;
	public:
		Array() {
			this->_arr = new T[0];
			this->_size = 0;
		}
		Array(unsigned int n) {
			this->_arr = new T[n];
			this->_size = n;
		}
		virtual ~Array() {
			delete[] this->_arr;
		}
		Array(Array const& origin) {
			this->_size = origin.size();
			this->_arr = new T[this->size()];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = origin._arr[i];
		}
		Array& operator=(Array const& origin) {
			if (this == &origin)
				return (*this);
			delete[] this->_arr;
			this->_size = origin.size();
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = origin._arr[i];
			return *this;
		}
		T& operator[](unsigned int idx) const {
			if (idx >= this->_size || idx < 0)
				throw Array::OutofLimitsException();
			return (this->_arr[idx]);
		}

		unsigned int size() const {
			return (this->_size);
		}

		class OutofLimitsException : public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return ("Error: elements out of limits");
				}
		};
		
};

#endif
