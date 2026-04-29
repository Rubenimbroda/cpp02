#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed::Fixed(const int integerValue)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits = integerValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	rawBits = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &output, const Fixed &fixedValue)
{
	output << fixedValue.toFloat();
	return output;
}
