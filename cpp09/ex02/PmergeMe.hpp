/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:49:07 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/14 16:53:16 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> vectorContainer;
        std::deque<int> dequeContainer;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& cpy);
        PmergeMe& operator=(const PmergeMe& cpy);
        void parse(char** argv);
        void mergeSort();
        int isInt(std::string str);
		void merge(std::vector<int>& arr, unsigned int pair);
		void swap(int& n1, int& n2);
		void sortPairs(std::vector<int>& pairs, int pairSize);
        ~PmergeMe();
};

#endif