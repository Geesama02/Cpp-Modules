/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:21:23 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/31 14:38:37 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename X> void swap(X& a, X& b) {
    X tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename X> X min(X a, X b) {
    if (a < b)
        return (a);
    else
        return (b);
}

template <typename X> X max(X a, X b) {
    if (a > b)
        return (a);
    else
        return (b);
}

#endif