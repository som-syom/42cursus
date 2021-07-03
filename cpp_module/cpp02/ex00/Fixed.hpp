#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private :
		int	value;
		static const int frac;
	public :
		Fixed();
		~Fixed();
		//복사생성자
		//오버로드
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif