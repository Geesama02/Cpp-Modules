/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:12:33 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/02 15:11:30 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float new_x, const float new_y) : x(new_x), y(new_y) {}
Point::Point(const Point& copy) : x(copy.x), y(copy.y) {}
Point& Point::operator=(const Point& to_copy)
{
	(void)to_copy;
	return (*this);
}
Point::~Point() {}
Fixed Point::getX() const { return (x); }
Fixed Point::getY() const { return (y); }