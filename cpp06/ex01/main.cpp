/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:46:35 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/30 11:06:38 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data mydata;
    mydata.data1 = 1;
    mydata.data2 = 2;
    mydata.data3 = 3;
    mydata.randomName = "I am random :P";
    std::cout << "address before -> " << &mydata << std::endl;
    uintptr_t ptr = Serializer::serialize(&mydata);
    Data *data_ptr = Serializer::deserialize(ptr);
    std::cout << "address after -> " << data_ptr << std::endl;
    std::cout << "data1 -> " << data_ptr->data1 << std::endl;
    std::cout << "data2 -> " << data_ptr->data2 << std::endl;
    std::cout << "data3 -> " << data_ptr->data3 << std::endl;
    std::cout << "randomName -> " << data_ptr->randomName << std::endl;
    return (0);
}