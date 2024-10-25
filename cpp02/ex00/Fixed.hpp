/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:17 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/25 11:38:11 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int fp_num;
		static const int fract = 8;
	public:
		Fixed ();
		Fixed (const Fixed& to_copy);
		Fixed& operator=(const Fixed& to_copy);
		~Fixed ();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif