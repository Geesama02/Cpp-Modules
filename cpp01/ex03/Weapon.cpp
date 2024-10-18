/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:09:00 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/18 11:11:52 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType(std::string str)
{
	type = str;
}

Weapon::Weapon(std::string str)
{
	setType(str);
}

const std::string& Weapon::getType() const
{
	return (type);
}