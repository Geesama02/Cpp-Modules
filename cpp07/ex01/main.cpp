/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:36:54 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/01 11:52:09 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printC(const T& x ) {
    std::cout << x << std::endl;
}

void print(int& x ) {
    x++;
    std::cout << x << std::endl;
}

int main() {
    int arr[] = { 0, 1, 2, 3, 4 };
    std::string names[] = { "name1", "name2", "name3" };
    iter(arr, 5, print);
    iter(names, 3, printC);
    iter(arr, 5, printC);
    return (0);
}