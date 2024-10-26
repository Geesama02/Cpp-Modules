/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:09 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/26 15:56:42 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	fp_num = 0;
	std::cout << "Default constructor called\n";
}
Fixed::Fixed ( const float val )
{
	setRawBits(roundf(val * (1 << fract)));
}
Fixed::Fixed ( const int val )
{
	setRawBits(val * (1 << fract));
}
Fixed::Fixed ( const Fixed& to_copy )
{
	std::cout << "Copy constructor called\n";
	*this = to_copy;
}
Fixed& Fixed::operator=( const Fixed& to_copy )
{
	std::cout << "Copy assignment operator called\n";
	if (this != &to_copy)
		setRawBits(to_copy.getRawBits());
	return (*this);
}
Fixed::~Fixed ( void )
{
	std::cout << "Destructor called\n";
}
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return (fp_num);
}
void Fixed::print(std::ostream& os) const
{
	os << toFloat();
}
void Fixed::setRawBits( int const raw )
{
	fp_num = raw;
}
float Fixed::toFloat( void ) const
{
	return ((float)getRawBits() / (float)(1 << fract));
}
int Fixed::toInt( void ) const
{
	return (getRawBits() >> fract);
}
std::ostream& operator<<(std::ostream& os, const Fixed& my_obj)
{
	my_obj.print(os);
	return (os);
}