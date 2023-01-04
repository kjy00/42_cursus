#include "./Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	fixed_point = num << Fixed::frac_bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(num * (1 << Fixed::frac_bits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixed_point = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const{
	return fixed_point;
}

void Fixed::setRawBits(int const raw_bits) {
	fixed_point = raw_bits;
}

int Fixed::toInt(void) const {
	return fixed_point >> Fixed::frac_bits;
}

float Fixed::toFloat(void) const {
	return float(fixed_point) / (1 << frac_bits);
}
std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed){
	return ostream << fixed.toFloat();
}
