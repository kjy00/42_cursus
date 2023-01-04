#include "./Fixed.hpp"

Fixed::Fixed(void) {
	fixed_point = 0;
}

Fixed::Fixed(const int num) {
	fixed_point = num << Fixed::frac_bits;
}

Fixed::Fixed(const float num) {
	fixed_point = roundf(num * (1 << Fixed::frac_bits));
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const Fixed& fixed) {
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed)
		this->fixed_point = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &fixed) {
	return fixed_point < fixed.fixed_point;
}

bool Fixed::operator>(const Fixed &fixed) {
	return fixed_point > fixed.fixed_point;
}

bool Fixed::operator==(const Fixed &fixed) {
	return fixed_point == fixed.fixed_point;
}

bool Fixed::operator!=(const Fixed &fixed) {
	return fixed_point != fixed.fixed_point;
}

bool Fixed::operator<=(const Fixed &fixed) {
	return fixed_point <= fixed.fixed_point;
}

bool Fixed::operator>=(const Fixed &fixed) {
	return fixed_point >= fixed.fixed_point;
}

Fixed Fixed::operator+(const Fixed &fixed) {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed &fixed) {
	Fixed tmp(this->toFloat() * fixed.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed &fixed) {
	Fixed tmp(this->toFloat() / fixed.toFloat());
	return tmp;
}

Fixed &Fixed::operator++() {
	fixed_point += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	fixed_point += 1;
	return temp;
}

Fixed &Fixed::operator--() {
	fixed_point -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	fixed_point -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}
const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}
Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed2;
	return fixed1;
}
const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed2;
	return fixed1;
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
