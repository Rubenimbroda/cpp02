#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
    rawBits = value <<fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
    rawBits = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return rawBits >> fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
	return rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.rawBits = rawBits + other.rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.rawBits = rawBits - other.rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long product;

	product = static_cast<long>(rawBits) * static_cast<long>(other.rawBits);
	result.rawBits = static_cast<int>(product >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long dividend;

	dividend = static_cast<long>(rawBits) << fractionalBits;
	result.rawBits = static_cast<int>(dividend / other.rawBits);
	return result;
}

Fixed &Fixed::operator++()
{
	++rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	++rawBits;
	return temp;
}

Fixed &Fixed::operator--()
{
	--rawBits;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	--rawBits;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
