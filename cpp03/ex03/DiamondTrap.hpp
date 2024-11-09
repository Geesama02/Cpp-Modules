/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:25:23 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/09 10:45:00 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name;
	public:
		DiamondTrap ();
		DiamondTrap (std::string new_name);
		DiamondTrap (const DiamondTrap& to_copy);
		DiamondTrap& operator=(const DiamondTrap& to_copy);
		~DiamondTrap ();
		void attack(const std::string& target);
		void whoAmI();
};

#endif