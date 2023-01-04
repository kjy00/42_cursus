#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int fixed_point;
		static const int frac_bits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed& fixed);
		Fixed &operator=(const Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw_bits);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);

#endif
