/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:36:54 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/01 15:51:39 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try
    {
        Array<int> myArr;
        std::cout << "Default class size -> " << myArr.size() << std::endl;
        Array<int> myArr2(5);
        Array<std::string> myArr3(3);
        myArr3[0] = "element1";
        myArr3[1] = "element2";
        myArr3[2] = "element3";
        Array<std::string> myArr4(myArr3);
        Array<std::string> myArr5 = myArr3;
        std::cout << "Class size -> " << myArr2.size() << std::endl;
        std::cout << "Int Array elements { ";
        for (size_t i = 0; i < myArr2.size(); i++) {
            std::cout << myArr2[i];
            if (i + 1 < myArr2.size())
                std::cout << ", ";
        } 
        std::cout << " }" << std::endl;
        std::cout << "Strings Array elements { ";
        for (size_t i = 0; i < myArr3.size(); i++) {
            std::cout << myArr3[i];
            if (i + 1 < myArr3.size())
                std::cout << ", ";
        } 
        std::cout << " }" << std::endl;
        std::cout << "Strings copy Constructor Array elements { ";
        for (size_t i = 0; i < myArr4.size(); i++) {
            std::cout << myArr4[i];
            if (i + 1 < myArr4.size())
                std::cout << ", ";
        } 
        std::cout << " }" << std::endl;
        std::cout << "Strings copy assignement operator Array elements { ";
        for (size_t i = 0; i < myArr4.size(); i++) {
            std::cout << myArr4[i];
            if (i + 1 < myArr4.size())
                std::cout << ", ";
        } 
        std::cout << " }" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    
    return (0);
}