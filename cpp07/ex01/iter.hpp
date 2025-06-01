/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:21:23 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/01 11:44:40 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename addr>
void iter(addr* arr, size_t length, void (*function)(const addr& param)) {
    for (size_t i = 0; i < length; i++) {
        function(arr[i]);
    }
}
template <typename addr>
void iter(addr* arr, size_t length, void (*function)(addr& param)) {
    for (size_t i = 0; i < length; i++) {
        function(arr[i]);
    }
}

#endif