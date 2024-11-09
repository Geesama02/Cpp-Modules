/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:25:41 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/09 10:07:02 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
	public:
		FragTrap ();
		FragTrap (std::string new_name);
		FragTrap (const FragTrap& to_copy);
		FragTrap& operator=(const FragTrap& to_copy);
		~FragTrap ();
		void highFivesGuys(void);
};

#endif