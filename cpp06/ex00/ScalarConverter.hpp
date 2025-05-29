/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:04:59 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/29 11:32:18 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <climits>
#include <cmath>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter& cpy);
        ScalarConverter& operator=(ScalarConverter& cpy);
        ~ScalarConverter();
    public:
        static void convert(std::string str);
};

#endif