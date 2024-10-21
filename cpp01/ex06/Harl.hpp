/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:06:51 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/21 12:16:28 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Harl::*debugPtr)(void);
		void (Harl::*infoPtr)(void);
		void (Harl::*warningPtr)(void);
		void (Harl::*errorPtr)(void);
	public:
		Harl();
		void complain( std::string level );
};

#endif