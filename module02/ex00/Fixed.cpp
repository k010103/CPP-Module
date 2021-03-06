#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}


Fixed &Fixed::operator = ( const Fixed &fixed )
{
	std::cout << "Assignment operator called" << std::endl;
	this->value = fixed.value;
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}