/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:56:02 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/28 17:09:31 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria **slots;
		static AMateria *dropped_inventory[1024];
	public:
		Character();
		Character(std::string new_name);
		Character(const Character& to_copy);
		Character& operator=(const Character& to_copy);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		static void cleanFloor();
};

#endif