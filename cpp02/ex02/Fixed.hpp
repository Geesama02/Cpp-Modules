/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:17 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/22 10:51:26 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {
	private:
		int fp_num;
		static const int fract = 8;
	public:
		Fixed ();
		Fixed (const Fixed& to_copy);
		Fixed ( const float val );
		Fixed ( const int val );
		Fixed& operator=(const Fixed& to_copy);
		~Fixed ();
		bool operator>(const Fixed& to_compare) const;
		bool operator<(const Fixed& to_compare) const;
		bool operator>=(const Fixed& to_compare) const;
		bool operator<=(const Fixed& to_compare) const;
		bool operator==(const Fixed& to_compare) const;
		bool operator!=(const Fixed& to_compare) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed& min(Fixed& f1, Fixed& f2);
		static const Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);
		void print(std::ostream& os) const;
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif