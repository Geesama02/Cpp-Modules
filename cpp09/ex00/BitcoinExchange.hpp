/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:49:07 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/03 19:47:56 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <errno.h>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::map<std::string, float> db;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& cpy);
        void parseData();
        int checkData(std::string& line);
        void checkDate(std::string& line);
        ~BitcoinExchange();
};

#endif