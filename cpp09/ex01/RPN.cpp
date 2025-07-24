/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:24:21 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/04 10:45:10 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& cpy) {
    s = cpy.s;
}
RPN& RPN::operator=(const RPN& cpy) {
    if (this != &cpy)
        s = cpy.s;
    return (*this);
}
void RPN::calculate(std::string rpn) {
    std::string::iterator it = rpn.begin();
    long long res = 0;
    while(it != rpn.end()) {
        if (*it == ' ') {
            it++;
            continue;
        }
        else if (std::isdigit(*it))
            s.push(*it - '0');
        else if (s.size() > 1
            && (*it == '+' || *it == '-' || *it == '*' || *it == '/') ) {
            long long num1 = s.top();
            s.pop();
            if (*it == '+')
                s.top() = num1 + s.top();
            else if (*it == '-')
                s.top() = s.top() - num1;   
            else if (*it == '*')
                s.top() = num1 * s.top();
            else if (*it == '/' && num1 == 0)
                throw std::logic_error("Error: Division by zero");
            else if (*it == '/')
                s.top() = s.top() / num1;        
        }
        else
            throw std::runtime_error("Error");
        it++;
    }
    if (s.size() > 1)
        throw std::runtime_error("Error");
    else if (!s.empty())
        res = s.top();
    std::cout << res << std::endl;
}
RPN::~RPN() {}