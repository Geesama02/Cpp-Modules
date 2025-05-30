/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:06 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/30 14:11:31 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void) {
    std::srand(time(NULL));
    if (std::rand() % 3 == 0)
        return (new A());
    else if (std::rand() % 3 == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << 'A';
    else if (dynamic_cast<B*>(p))
        std::cout << 'B';
    else if (dynamic_cast<C*>(p))
        std::cout << 'C';
}

void identify(Base& p) {
    try
    {
        dynamic_cast<A&>(p);
        std::cout << 'A';
    }
    catch(std::exception& e) {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << 'B';
    }
    catch(std::exception& e) {}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << 'C';
    }
    catch(std::exception& e) {}
}

int main() {
    Base* base = generate();
    
    std::cout << "Type of Base is -> ";
    identify(base);
    std::cout << "\n";
    std::cout << "Type of Base is -> ";
    identify(*base);
    std::cout << "\n";
    delete base;
    return (0);
}