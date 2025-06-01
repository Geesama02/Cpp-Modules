/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:29:21 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/01 15:50:06 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    arr = NULL;
    arrSize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    if (n > 0)
        arr = new T[n]();
    else
        arr = NULL;
    arrSize = n;
}

template <typename T>
Array<T>::Array(const Array& cpy) {
    if (cpy.arrSize == 0)
        arr = NULL;
    else {
        arr = new T[cpy.arrSize];
        arrSize = cpy.arrSize;
        for (unsigned int i = 0; i < cpy.arrSize; i++) {
            arr[i] = cpy.arr[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& cpy) {
    if (this != &cpy) {
        if (cpy.arrSize == 0) {
            delete[] arr;
            arr = NULL;
            arrSize = 0;
        }
        else {
            delete[] arr;
            arr = new T[cpy.arrSize];
            arrSize = cpy.arrSize;
            for (unsigned int i = 0; i < cpy.arrSize; i++) {
                arr[i] = cpy.arr[i];
            }
        }
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const {
    if (index < arrSize) {
        return (arr[index]);
    }
    throw std::exception();
}

template <typename T>
unsigned int Array<T>::size() const {
    return (arrSize);
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}