/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:24:21 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/03 20:10:17 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    parseData();
}
void BitcoinExchange::checkDate(std::string& line) {
    tm tm;
    // std::istringstream ss(line);
    // ss >> std::get_time(&tm, "%Y-%m-%d");
    strptime(line.c_str(), "%Y-%m-%d", &tm);
    // if (ss.fail())
    //     throw std::runtime_error("Invalid DB file!");
    time_t date = mktime(&tm);
    // std::cout << "Date -> " <<  << std::endl;
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&date));
    std::cout << "Date " << ": " << buffer << " (time_t: " << date << ")" << std::endl;
}
int BitcoinExchange::checkData(std::string& line) {
    size_t pos = line.find(",");
    if (pos == std::string::npos)
        throw std::runtime_error("Invalid DB file!");
    std::string date;
    std::string price;
    date = line.substr(0, pos);
    checkDate(date);
    price = line.substr(pos + 1);
    float val = strtof(price.c_str(), NULL);
    if (errno == ERANGE)
        throw std::runtime_error("Invalid Price!");
    db[date] = val;
    return (0);
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