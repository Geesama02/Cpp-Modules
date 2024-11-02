/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:09 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/02 15:06:00 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	fp_num = 0;
	// std::cout << "Default constructor called\n";
}
Fixed::Fixed ( const float val )
{
	// std::cout << "Float constructor called\n";
	setRawBits(roundf(val * (1 << fract)));
}
Fixed::Fixed ( const int val )
{
	// std::cout << "Int constructor called\n";
	setRawBits(val * (1 << fract));
}
Fixed::Fixed ( const Fixed& to_copy )
{
	// std::cout << "Copy constructor called\n";
	*this = to_copy;
}
Fixed& Fixed::operator=( const Fixed& to_copy )
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &to_copy)
		setRawBits(to_copy.getRawBits());
	return (*this);
}
Fixed::~Fixed ( void )
{
	// std::cout << "Destructor called\n";
}
int Fixed::getRawBits( void ) const
{
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
bool Fixed::operator>(const Fixed& to_compare) { return (fp_num > to_compare.fp_num); }
bool Fixed::operator<(const Fixed& to_compare) { return (fp_num < to_compare.fp_num); }
bool Fixed::operator>=(const Fixed& to_compare) { return (fp_num >= to_compare.fp_num); }
bool Fixed::operator<=(const Fixed& to_compare) { return (fp_num <= to_compare.fp_num); }
bool Fixed::operator==(const Fixed& to_compare) { return (fp_num == to_compare.fp_num); }
bool Fixed::operator!=(const Fixed& to_compare) { return (fp_num != to_compare.fp_num); }
Fixed Fixed::operator+(const Fixed& other) { return (Fixed(this->toFloat() + other.toFloat())); }
Fixed Fixed::operator-(const Fixed& other) { return (Fixed(this->toFloat() - other.toFloat())); }
Fixed Fixed::operator*(const Fixed& other) { return (Fixed(this->toFloat() * other.toFloat())); }
Fixed Fixed::operator/(const Fixed& other) { return (Fixed(this->toFloat() / other.toFloat())); }

Fixed& Fixed::operator++()
{
	fp_num++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	fp_num++;
	return (tmp);
}
Fixed& Fixed::operator--()
{
	fp_num--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	fp_num--;
	return (tmp);
}
Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.fp_num < f2.fp_num)
		return (f1);
	return (f2);
}
Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.fp_num > f2.fp_num)
		return (f1);
	return (f2);
}