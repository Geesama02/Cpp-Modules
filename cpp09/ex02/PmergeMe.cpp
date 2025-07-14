/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:09:59 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/14 16:54:25 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& cpy) {
    vectorContainer = cpy.vectorContainer;
    dequeContainer = cpy.dequeContainer;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& cpy) {
    if (this != &cpy) {
        vectorContainer = cpy.vectorContainer;
        dequeContainer = cpy.dequeContainer;
    }
    return (*this);
}
int PmergeMe::isInt(std::string str) {
    size_t i = 0;
    while(str.size() && *str.rbegin() == ' ') {
        str.erase(str.size() - 1);
    }
    while(str.size() && str[0] == ' ') {
        str.erase(0, 1);
    }
    for (i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] == '+')
            continue;
        if (!std::isdigit(str[i]))
            return (0);
    }
    long long tmp = std::atol(str.c_str());
    if (i > 11 || tmp > INT_MAX || str.empty())
        return (0);
    return (1);
}

// delete later
void printVector(std::string title, std::vector<int> vec) {
	std::cout << title << " -> ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::swap(int& n1, int& n2) {
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
}

void PmergeMe::sortPairs(std::vector<int>& pairs, int pairSize) {
    // for (std::vector<int>::iterator it = pairs.begin(); it != pairs.end(); it++) {
	// 	if (it-> > it->back())
	// 		swap(it->front(), it->back());
	// }
	unsigned int i = 0;
	while(i < pairs.size()) {
		if (pairs[i + pairSize / 2 - 1] > pairs[i + pairSize - 1]) {
			std::cout << "pairs[i + pairSize / 2 - 1] -> " << pairs[i + pairSize / 2 - 1] << std::endl; 
			std::cout << "pairs[i + pairSize - 1] -> " << pairs[i + pairSize - 1] << std::endl; 
		}
		i += pairSize;
	}
}

void PmergeMe::merge(std::vector<int>& arr, unsigned int pairSize) {
	std::cout << "size -> " << arr.size() << std::endl;
	pairSize *= 2;
	std::cout << "pairSize -> " << pairSize << std::endl;
	// std::vector<std::vector<int> > pairSizes;
	if (pairSize > (arr.size() / 2))
		return ;
    // }
	sortPairs(arr, pairSize);
	std::vector<int> tmp;
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		tmp.push_back(*it);
        if (tmp.size() == pairSize) {
			printVector("Pair", tmp);
			tmp.clear();
		}
	}
	printVector("Leftover", tmp);
	std::cout << '\n';
	std::cout << "==========================" << std::endl;
	merge(arr, pairSize);
	// int p1 = arr.size() / 2;
	// int p2 = arr.size() - p1;
	// std::cout << "p2 -> " << p2 << std::endl;
	// std::vector<int> part1;
	// part1.insert(part1.begin(), arr.begin(), arr.begin() + p1);
	// std::vector<int> part2;
	// part2.insert(part2.begin(), arr.begin() + p1, arr.begin() + arr.size());
	// std::cout << "Part1:   ";
    // for (std::vector<int>::iterator it = part1.begin(); it != part1.end(); it++) {
    //     std::cout << *it << ' ';
    // }
    // std::cout << std::endl;
	// std::cout << "Part2:   ";
    // for (std::vector<int>::iterator it = part2.begin(); it != part2.end(); it++) {
    //     std::cout << *it << ' ';
    // }
    // std::cout << std::endl;
	// merge(part1, pair);
	// merge(part2, pair);
}

void PmergeMe::mergeSort() {
    std::cout << "Before:   ";
    for (std::vector<int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
	merge(vectorContainer, 1);
}
void PmergeMe::parse(char** argv) {
    argv++;
    while(*argv) {
        // std::cout << *argv << std::endl;
        if (!isInt(*argv))
            throw std::runtime_error("Invalid Number!");
        int num = std::atoi(*argv);
        vectorContainer.push_back(num);
        dequeContainer.push_back(num);
        argv++;
    }
}
PmergeMe::~PmergeMe() {}