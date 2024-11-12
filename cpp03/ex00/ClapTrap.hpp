/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:17 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/07 10:51:39 by oait-laa         ###   ########.fr       */
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
		std::string getName();
		int getHitPoints();
		int getEnergyPoints();
		int getAttackDamage();
		void setName(std::string newName);
		void setHitPoints(int HitPoints);
		void setEnergyPoints(int EnergyPoints);
		void setAttackDamage(int AttackDamage);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif