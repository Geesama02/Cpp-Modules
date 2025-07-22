/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:49:07 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/22 15:07:13 by oait-laa         ###   ########.fr       */
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
#include <climits>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::map<time_t, float> db;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& cpy);
        void parseData();
		int isInt(std::string str);
        void evaluate(std::string file);
        int checkData(std::string& line);
        float getCorrectDate(std::string line);
        time_t getDate(std::string& line);
        ~BitcoinExchange();
};

#endif