/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:45:22 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/02 14:23:02 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& cpy);
        Span& operator=(const Span& cpy);
        std::vector<int>& getNumbers();
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        void generator(std::vector<int>::iterator start, std::vector<int>::iterator end);
        ~Span();
};

#endif