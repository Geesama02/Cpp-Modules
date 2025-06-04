/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:24:21 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/04 10:45:10 by oait-laa         ###   ########.fr       */
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
    // char buffer[80];
    // std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&date));
    // std::cout << "Date " << ": " << buffer << " (time_t: " << date << ")" << std::endl;
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

float BitcoinExchange::getCorrectDate(std::string& line) {
    tm tm = {};
    if (line.size() != 10 || !strptime(line.c_str(), "%Y-%m-%d", &tm))
        throw std::runtime_error("invalid date.");
    time_t date = mktime(&tm);
    if (date == -1)
        throw std::runtime_error("invalid date.");
    if (db.find(date) == db.end()) {
        if (db.upper_bound(date) == db.begin())
            return (db.begin()->second);
        else
            return ((db.upper_bound(date)--)->second);
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
                size_t pos = line.find(" | ");
                if (pos == std::string::npos)
                    throw std::runtime_error("bad input => " + line);
                std::string date;
                std::string value;
                date = line.substr(0, pos);
                value = line.substr(pos + 3);
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