/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:00:37 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/09 10:07:20 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:
		ScavTrap ();
		ScavTrap (std::string new_name);
		ScavTrap (const ScavTrap& to_copy);
		ScavTrap& operator=(const ScavTrap& to_copy);
		~ScavTrap ();
		void guardGate();
		void attack(const std::string& target);
		
};

#endif