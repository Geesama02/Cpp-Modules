/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:17 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/24 11:54:33 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public:
		ClapTrap ();
		ClapTrap (std::string new_name);
		ClapTrap (const ClapTrap& to_copy);
		ClapTrap& operator=(const ClapTrap& to_copy);
		~ClapTrap ();
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		void setName(std::string newName);
		void setHitPoints(int HitPoints);
		void setEnergyPoints(int EnergyPoints);
		void setAttackDamage(int AttackDamage);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif