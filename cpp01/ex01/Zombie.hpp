/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:39:40 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 16:21:42 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie{
	private:
		std::string name;
	public:
		Zombie( std::string name );
		Zombie( void );
		void announce( void );
		std::string getName();
		void setName(std::string newName);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif