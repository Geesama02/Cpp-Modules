/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sama <sama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:49:07 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/18 14:59:08 by sama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<long long> s;
    public:
        RPN();
        RPN(const RPN& cpy);
        RPN& operator=(const RPN& cpy);
        void calculate(std::string rpn);
        ~RPN();
};

#endif