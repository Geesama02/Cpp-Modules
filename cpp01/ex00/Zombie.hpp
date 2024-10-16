/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:39:40 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 15:25:58 by oait-laa         ###   ########.fr       */
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
		void announce( void );
		std::string getName();
		void setName(std::string newName);
		~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif