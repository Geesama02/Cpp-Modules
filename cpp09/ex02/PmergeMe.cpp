/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:09:59 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/16 16:51:43 by oait-laa         ###   ########.fr       */
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
void printVectorT(std::string title, std::vector<int> vec) {
	std::cout << title << " -> ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
void printVector(std::vector<int> vec) {
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ' ';
    }
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
	while(i + pairSize - 1 < pairs.size()) {
		// std::cout << "pairs[i + pairSize / 2 - 1] -> " << pairs[i + pairSize / 2 - 1] << std::endl; 
		// std::cout << "pairs[i + pairSize - 1] -> " << pairs[i + pairSize - 1] << std::endl; 
		if (pairs[i + pairSize / 2 - 1] > pairs[i + pairSize - 1]) {
			unsigned int j = i;
			// std::cout << "Pair inside -> ";
			// while (j != (i + pairSize)) {
			// 	// std::cout << "Before swapped -> " << pairs[j] << ", " << pairs[j + pairSize / 2] << std::endl;
			// 	std::cout << pairs[j] << ' ';
			// 	j++;
			// }
			// std::cout << std::endl;
			// j = i;
			while (j != (i + pairSize / 2)) {
				// std::cout << "Before swapped -> " << pairs[j] << ", " << pairs[j + pairSize / 2] << std::endl;
				swap(pairs[j], pairs[j + pairSize / 2]);
				// std::cout << "swapped -> " << pairs[j] << ", " << pairs[j + pairSize / 2] << std::endl;
				j++;
			}
		}
		i += pairSize;
	}
}

int PmergeMe::jacobsthalNum(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

std::vector<int> PmergeMe::getJacobsthalIndex(int n) {
	int i = 3;
	std::vector<int> indexs;
	while (i <= n) {
		int index = jacobsthalNum(i);
		if (index > n)
			break;
		indexs.push_back(index);
		int prevIndex = jacobsthalNum(i - 1);
		int diff = index - prevIndex;
		int j = 1;
		while(j < diff) {
			indexs.push_back(index - j);
			j++;
		}
		i++;
	}
	return (indexs);
}

bool comp(const std::vector<int>& a, const std::vector<int>& b) {
	return (a.back() < b.back());
}

int getOrder(std::vector<int> indexes, int n) {
	int c = 3;
	for(std::vector<int>::iterator it = indexes.begin(); it != indexes.end(); it++) {
		if (*it == n)
			break;
		if (*it < n)
			c++;
	}
	return (c);
}

void PmergeMe::insert(std::vector<int>& pairs, unsigned int pairSize) {
	unsigned int i = 0;
	std::vector<std::vector<int> > pend;
	std::vector<std::vector<int> > main;
	std::vector<int> unused;
	unsigned int j = 0;
	while((i + pairSize / 2) <= pairs.size()) {
		j = i;
		std::vector<int> tmp;
		while (j < (i + pairSize / 2) && (i + pairSize / 2) <= pairs.size())
			tmp.push_back(pairs[j++]);
		if (!tmp.empty() && i != 0)
			pend.push_back(tmp);
		else if (!tmp.empty() && i == 0)
			main.push_back(tmp);
		tmp.clear();
		while (j < (i + pairSize) && (i + pairSize) <= pairs.size())
			tmp.push_back(pairs[j++]);
		if (!tmp.empty())
			main.push_back(tmp);
		i += pairSize;
	}
	while (j < pairs.size()) {
		unused.push_back(pairs[j]);
		j++;
	}
	std::cout << "Main -> ";
	for(std::vector<std::vector<int> >::iterator it = main.begin(); it != main.end(); it++) {
		std::cout << "( ";
		printVector(*it);
		std::cout << ") ";
	}
	std::cout << std::endl;
	std::cout << "Pend -> ";
	for(std::vector<std::vector<int> >::iterator it = pend.begin(); it != pend.end(); it++) {
		std::cout << "( ";
		printVector(*it);
		std::cout << ") ";
	}
	std::cout << std::endl;
	printVectorT("Unused -> ", unused);
	// std::cout << "Num -> " << pend.size() + 1 << std::endl;
	// std::cout << "jacobsthalNum -> " << jacobsthalNum(pend.size() + 1) << std::endl;
	std::vector<int> indexs = getJacobsthalIndex(pend.size() + 1);
	printVectorT("Indexs", indexs);
	for(std::vector<int>::iterator it = indexs.begin(); it != indexs.end(); it++) {
		std::vector<std::vector<int> >::iterator it2 = std::upper_bound(main.begin(), main.begin() + getOrder(indexs, *it), pend[*it - 2], comp);
		// std::cout << "getOrder(indexs, *it) -> " << getOrder(indexs, *it) << std::endl;
		std::cout << "checking -> ";
		std::cout << "( ";
		printVector(pend[*it - 2]);
		std::cout << ") ";
		std::cout << "in -> ";
		std::cout << "( ";
		printVector(*it2);
		std::cout << ") ";
		std::cout << "-> " << it2->back() << std::endl;
		main.insert(it2, pend[*it - 2]);
	}
	std::cout << "Main After -> ";
	for(std::vector<std::vector<int> >::iterator it = main.begin(); it != main.end(); it++) {
		std::cout << "( ";
		printVector(*it);
		std::cout << ") ";
	}
}

void PmergeMe::merge(std::vector<int>& arr, unsigned int pairSize) {
	std::cout << "size -> " << arr.size() << std::endl;
	pairSize *= 2;
	// std::vector<std::vector<int> > pairSizes;
	if (pairSize > arr.size())
		return ;
    // }
	sortPairs(arr, pairSize);
	// std::vector<int> tmp;
    // for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
	// 	// std::cout << "Pushed -> " << *it << std::endl;
	// 	tmp.push_back(*it);
    //     if (tmp.size() == pairSize) {
	// 		printVectorT("Pair", tmp);
	// 		tmp.clear();
	// 	}
	// }
	// printVectorT("Leftover", tmp);
	printVectorT("Final Seq", arr);
	std::cout << "==========================" << std::endl;
	merge(arr, pairSize);
	insert(arr, pairSize);
	std::cout << "pairSize -> " << pairSize << std::endl;
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