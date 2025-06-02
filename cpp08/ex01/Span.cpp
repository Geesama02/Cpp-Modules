/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:53:39 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/02 15:31:19 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() { N = 0; }
Span::Span(unsigned int n) { 
    N = n;
    numbers.reserve(N);
}
Span::Span(const Span& cpy) {
    N = cpy.N;
    numbers = cpy.numbers;
    numbers.reserve(N);
}
Span& Span::operator=(const Span& cpy) {
    if (this != &cpy) {
        N = cpy.N;
        numbers = cpy.numbers;
        numbers.reserve(N);
    }
    return (*this);
}
std::vector<int>& Span::getNumbers() {
    return (numbers);
}


void Span::addNumber(int num) {
    if (numbers.size() < N)
        numbers.push_back(num);
    else
        throw std::exception();
}

int Span::shortestSpan() {
    if (numbers.size() < 2)
        throw std::exception();
    std::sort(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator it;
    int shortest = numbers[1] - numbers[0];
    for (it = numbers.begin(); it != numbers.end(); it++) {
        if ((it + 1) != numbers.end()) {
            if ((*(it + 1) - *it) < shortest)
            shortest = *(it + 1) - *it;
        }
    }
    return (shortest);
}

int Span::longestSpan() {
    if (numbers.size() < 2)
        throw std::exception();
    std::sort(numbers.begin(), numbers.end());
    int longest = *numbers.rbegin() - *numbers.begin();
    return (longest);
}

void Span::generator(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    unsigned int len = std::distance(start, end);
    if (len + numbers.size() > N)
        throw std::exception();
    else
        numbers.insert(numbers.end(), start, end);
}

Span::~Span() {}