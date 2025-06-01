/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:29:25 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/01 15:50:12 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T* arr;
        unsigned int arrSize;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& cpy);
        Array& operator=(const Array& cpy);
        T& operator[](unsigned int index) const;
        unsigned int size() const;
        ~Array();
};

#include "Array.tpp"

#endif