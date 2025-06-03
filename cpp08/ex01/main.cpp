/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:36:54 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/03 12:09:03 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

int n() {
    static int i = 0;
    return (i++);
}

int main()
{
    try
    {
        Span sp = Span(10005);
        std::vector<int> Data(10000);
        std::generate(Data.begin(), Data.end(), n);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.generator(Data.begin(), Data.end());
        std::cout << "new values -> { ";
        for (std::vector<int>::iterator it = sp.getNumbers().begin(); it != sp.getNumbers().end(); it++) {
            std::cout << *it << ", ";
        }
        std::cout << "}" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}