#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int fixed_point;
		static const int frac_bits = 8;
	public:
		int getRawBits(void) const;
		void setRawBits(int const raw_bits);
		Fixed();
		~Fixed();
		Fixed(const Fixed& fixed);
		Fixed &operator=(const Fixed &fixed);
};

#endif
