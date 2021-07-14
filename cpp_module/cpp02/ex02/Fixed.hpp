#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private :
		int	value;
		static const int frac = 8;
	public :
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(Fixed const&);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
		Fixed& operator=(const Fixed&);

		bool operator<(const Fixed&);
		bool operator>(const Fixed&);
		bool operator<=(const Fixed&);
		bool operator>=(const Fixed&);
		bool operator==(const Fixed&);
		bool operator!=(const Fixed&);

		float operator+(const Fixed&);
		float operator-(const Fixed&);
		float operator*(const Fixed&);
		float operator/(const Fixed&);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed&, Fixed&);
		static Fixed& max(Fixed&, Fixed&);
		static const Fixed& min(const Fixed&, const Fixed&);
		static const Fixed& max(const Fixed&, const Fixed&);

};

std::ostream&	operator<<(std::ostream &out, const Fixed &f);


#endif