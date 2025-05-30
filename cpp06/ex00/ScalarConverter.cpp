/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:07:30 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/30 09:22:31 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& cpy) { 
    (void)cpy;
}
ScalarConverter& ScalarConverter::operator=(ScalarConverter& cpy) {
    (void)cpy;
    return (*this);
}
int isChar(std::string str) {
    if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return (1);
    return (0);
}
int isInt(std::string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (!std::isdigit(str[i]))
            return (0);
    }
    return (1);
}
int isFloat(std::string str) {
    if (!(str.size() > 3 && *str.rbegin() == 'f'))
        return (0);
    if (str[0] == '.' || str[str.size() - 2] == '.')
        return (0);
    int pointRep = 0;
    for (size_t i = 0; i < str.size() - 1; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (str[i] == '.' && pointRep == 0) {
            pointRep++;
            continue;
        }
        if (!std::isdigit(str[i]))
            return (0);
    }
    if (!pointRep)
        return (0);
    return (1);
}
int isDouble(std::string str) {
    if (str[0] == '.' || str[str.size() - 1] == '.')
        return (0);
    int pointRep = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (str[i] == '.' && pointRep == 0) {
            pointRep++;
            continue;
        }
        if (!std::isdigit(str[i]))
            return (0);
    }
    return (1);
}
void handleChar(std::string str) {
    std::cout << "char: " << str[0] << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}
void handleNum(std::string str) {
    double val;
    char *str_end;
    errno = 0;
    val = strtod(str.c_str(), &str_end);
    char c = static_cast<char>(val);
    if (errno == ERANGE)
        std::cout << "char: " << "impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
    if (errno == ERANGE || val < INT_MIN || val > INT_MAX)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    float val_f = static_cast<float>(val);
    if (errno == ERANGE || val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
        std::cout << "float: " << "impossible" << std::endl;
    else {
        if (val_f == floorf(val_f))
            std::cout << "float: " << val_f << ".0f" << std::endl;
        else
            std::cout << "float: " << val_f << "f" << std::endl;   
    }
    if (errno == ERANGE)
        std::cout << "double: " << "impossible" << std::endl;
    else {
        double val_d = static_cast<double>(val);
        if (!std::fmod(val_d, 1.0))
            std::cout << "double: " << val_d << ".0" << std::endl;
        else
            std::cout << "double: " << val_d << std::endl;
    }
}
void handleErr() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
void handleSpecial(std::string& str) {
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    char *str_end;
    double val;
    val = strtof(str.c_str(), &str_end);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}
void ScalarConverter::convert(std::string str) {
    if (str == "nan" || str == "+inf" || str == "-inf" 
        || str == "nanf" || str == "+inff" || str == "-inff") {
        handleSpecial(str);
        return ;
    }
    else if (isChar(str))
        handleChar(str);
    else if (isInt(str))
        handleNum(str);
    else if (isFloat(str))
        handleNum(str);
    else if (isDouble(str))
        handleNum(str);
    else
        handleErr();
}
ScalarConverter::~ScalarConverter() {}