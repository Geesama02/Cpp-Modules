/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:20:08 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/13 11:13:44 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross_p1 = (b.getX() - a.getX()) * (point.getY() - a.getY())
				- (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed cross_p2 = (c.getX() - b.getX()) * (point.getY() - b.getY())
				- (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed cross_p3 = (a.getX() - c.getX()) * (point.getY() - c.getY())
				- (a.getY() - c.getY()) * (point.getX() - c.getX());

	if ((cross_p1 > 0 && cross_p2 > 0 && cross_p3 > 0)
		|| (cross_p1 < 0 && cross_p2 < 0 && cross_p3 < 0))
		return (true);
	return (false);
}