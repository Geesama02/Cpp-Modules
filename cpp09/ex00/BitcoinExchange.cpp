/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:24:21 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/23 10:50:11 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    parseData();
}
time_t BitcoinExchange::getDate(std::string& line) {
    tm tm = {};
    strptime(line.c_str(), "%Y-%m-%d", &tm);
    time_t date = mktime(&tm);
    if (date == -1)
        throw std::runtime_error("Invalid DB file!");
    return (date);
}
int BitcoinExchange::checkData(std::string& line) {
    size_t pos = line.find(",");
    if (pos == std::string::npos)
        throw std::runtime_error("Invalid DB file!");
    std::string date;
    std::string price;
    date = line.substr(0, pos);
    price = line.substr(pos + 1);
    float val = strtof(price.c_str(), NULL);
    if (errno == ERANGE)
        throw std::runtime_error("too large a number.");
    db[getDate(date)] = val;
    return (0);
}

int BitcoinExchange::isInt(std::string str) {
    size_t i = 0;
    for (i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i]))
            return (0);
    }
    long long tmp = std::atol(str.c_str());
    if (i > 11 || tmp > INT_MAX || str.empty() || str == "+")
        return (0);
    return (1);
}

int BitcoinExchange::isDouble(std::string& str) {
	while(str.size() && *str.rbegin() == ' ') {
        str.erase(str.size() - 1);
    }
    while(str.size() && str[0] == ' ') {
        str.erase(0, 1);
    }
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

float BitcoinExchange::getCorrectDate(std::string line) {
    tm tm = {};
	size_t pos = line.find('-');
	std::string oldLine = line;
	if (pos == std::string::npos)
        throw std::runtime_error("bad input => " + oldLine);
	std::string year = line.substr(0, pos);
	line.erase(0, pos + 1);
    if (!isInt(year) || !strptime(line.c_str(), "%m-%d", &tm))
        throw std::runtime_error("bad input => " + oldLine);
	int y = std::atoi(year.c_str());
	if (y < 1900)
		tm.tm_year = 0;
	else
		tm.tm_year = y - 1900;
    time_t date = mktime(&tm);
    if (date == -1)
        throw std::runtime_error("bad input => " + oldLine);
    if (db.find(date) == db.end()) {
        if (db.upper_bound(date) == db.begin())
            return (db.begin()->second);
        else
            return ((--db.upper_bound(date))->second);
    }
    else
        return (db[date]);
}

void BitcoinExchange::evaluate(std::string file) {
    
        std::ifstream data(file.c_str());
        if (!data)
            throw std::runtime_error("file not found!");
        std::string line;
        if (!std::getline(data, line))
            throw std::runtime_error("invalid file!");
        while(std::getline(data, line)) {
            try
            {
				if (line.empty())
					continue;
                size_t pos = line.find(" | ");
                if (pos == std::string::npos)
                    throw std::runtime_error("bad input => " + line);
                std::string date;
                std::string value;
                date = line.substr(0, pos);
                value = line.substr(pos + 3);
				if (value.empty() || !isDouble(value))
                    throw std::runtime_error("bad input => " + line);
                float val = strtof(value.c_str(), NULL);
                if (val < 0)
                    throw std::runtime_error("not a positive number.");
                if (errno == ERANGE || val > 1000)
                    throw std::runtime_error("too large a number.");
                float exRate = getCorrectDate(date) * val;
                std::cout << date << " => " << value << " = " << exRate << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: " << e.what() << '\n';
            }
        }
}

void BitcoinExchange::parseData() {
    std::ifstream data("data.csv");
    if (!data)
        throw std::runtime_error("DB file not found!");
    std::string line;
	if (!std::getline(data, line))
		throw std::runtime_error("Invalid DB file!");
    while (std::getline(data, line)) {
        checkData(line);
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {
    db = cpy.db;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy) {
    if (this != &cpy)
        db = cpy.db;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}