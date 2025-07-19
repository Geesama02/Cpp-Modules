/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:09:59 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/19 16:39:24 by oait-laa         ###   ########.fr       */
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
    if (i > 11 || tmp > INT_MAX || str.empty() || str == "+")
        return (0);
    return (1);
}

// delete later
// void printVectorT(std::string title, std::vector<int> vec) {
// 	std::cout << title << " -> ";
//     for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
//         std::cout << *it << ' ';
//     }
//     std::cout << std::endl;
// }
// void printVector(std::vector<int> vec) {
//     for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
//         std::cout << *it << ' ';
//     }
// }

void swap(int& n1, int& n2) {
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
}

template <typename Container>
void sortPairs(Container& pairs, int pairSize) {
	unsigned int i = 0;
	while(i + pairSize - 1 < pairs.size()) { 
		if (pairs[i + pairSize / 2 - 1] > pairs[i + pairSize - 1]) {
			unsigned int j = i;
			while (j != (i + pairSize / 2)) {
				swap(pairs[j], pairs[j + pairSize / 2]);
				j++;
			}
		}
		i += pairSize;
	}
}

int jacobsthalNum(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

template <typename Container>
Container getJacobsthalIndex(int n) {
	int i = 3;
	Container indexs;
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
	i = jacobsthalNum(i - 1);
	while ((int)indexs.size() < n - 1) {
		if (std::find(indexs.begin(), indexs.end(), i) == indexs.end())
			indexs.push_back(i);
		i++;
	}
	return (indexs);
}

template <typename Container>
bool comp(const Container& a, const Container& b) {
	return (a.back() < b.back());
}
// template <typename Container>
// int getOrder(Container indexes, int n) {
// 	int c = 3;
// 	if (indexes.size() == 1)
// 		c = 2;
// 	for(Container::iterator it = indexes.begin(); it != indexes.end(); it++) {
// 		if (*it == n)
// 			break;
// 		c++;
// 	}
// 	return (c);
// }

template <typename Pairs, typename Container>
void insert(Container& pairs, unsigned int pairSize) {
	unsigned int i = 0;
	Pairs pend;
	Pairs main;
	Container unused;
	unsigned int j = 0;
	while((i + pairSize / 2) <= pairs.size()) {
		j = i;
		Container tmp;
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
	Container indexs = getJacobsthalIndex<Container>(pend.size() + 1);
	for(typename Container::iterator it = indexs.begin(); it != indexs.end(); it++) {
		int index = *it - 2;
		if (index < 0)
			index = 0;
		typename Pairs::iterator it2;
		if (*it + (it - indexs.begin()) > (int)main.size() - 1)
			it2 = std::upper_bound(main.begin(), main.end(), pend[index], comp<Container>);
		else
			it2 = std::upper_bound(main.begin(), main.begin() + *it + (it - indexs.begin()) + 1, pend[index], comp<Container>);
		main.insert(it2, pend[index]);
	}
	pairs.clear();
	for(typename Pairs::iterator it = main.begin(); it != main.end(); it++) {
		for (typename Container::iterator it2 = it->begin(); it2 != it->end(); it2++)
			pairs.push_back(*it2);
	}
	for (typename Container::iterator it = unused.begin(); it != unused.end(); it++) {
		pairs.push_back(*it);
	}
}
// void PmergeMe::insert(std::vector<int>& pairs, unsigned int pairSize) {
// 	unsigned int i = 0;
// 	std::vector<std::vector<int> > pend;
// 	std::vector<std::vector<int> > main;
// 	std::vector<int> unused;
// 	unsigned int j = 0;
// 	while((i + pairSize / 2) <= pairs.size()) {
// 		j = i;
// 		std::vector<int> tmp;
// 		while (j < (i + pairSize / 2) && (i + pairSize / 2) <= pairs.size())
// 			tmp.push_back(pairs[j++]);
// 		if (!tmp.empty() && i != 0)
// 			pend.push_back(tmp);
// 		else if (!tmp.empty() && i == 0)
// 			main.push_back(tmp);
// 		tmp.clear();
// 		while (j < (i + pairSize) && (i + pairSize) <= pairs.size())
// 			tmp.push_back(pairs[j++]);
// 		if (!tmp.empty())
// 			main.push_back(tmp);
// 		i += pairSize;
// 	}
// 	while (j < pairs.size()) {
// 		unused.push_back(pairs[j]);
// 		j++;
// 	}
// 	std::vector<int> indexs = getJacobsthalIndex(pend.size() + 1);
// 	for(std::vector<int>::iterator it = indexs.begin(); it != indexs.end(); it++) {
// 		int index = *it - 2;
// 		if (index < 0)
// 			index = 0;
// 		std::vector<std::vector<int> >::iterator it2;
// 		if (*it + (it - indexs.begin()) > (int)main.size() - 1)
// 			it2 = std::upper_bound(main.begin(), main.end(), pend[index], comp);
// 		else
// 			it2 = std::upper_bound(main.begin(), main.begin() + *it + (it - indexs.begin()) + 1, pend[index], comp);
// 		main.insert(it2, pend[index]);
// 	}
// 	pairs.clear();
// 	for(std::vector<std::vector<int> >::iterator it = main.begin(); it != main.end(); it++) {
// 		for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			pairs.push_back(*it2);
// 	}
// 	for (std::vector<int>::iterator it = unused.begin(); it != unused.end(); it++) {
// 		pairs.push_back(*it);
// 	}
// }
template <typename Pairs, typename Container>
void merge(Container& arr, unsigned int pairSize) {
	pairSize *= 2;
	if (pairSize > arr.size())
		return ;
	sortPairs<Container>(arr, pairSize);
	merge<Pairs, Container>(arr, pairSize);
	insert<Pairs, Container>(arr, pairSize);
}
// void PmergeMe::merge(std::vector<int>& arr, unsigned int pairSize) {
// 	pairSize *= 2;
// 	if (pairSize > arr.size())
// 		return ;
// 	sortPairs(arr, pairSize);
// 	merge(arr, pairSize);
// 	insert(arr, pairSize);
// }

double PmergeMe::timeNow() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec + (tv.tv_usec / 1000000.0));
}

void PmergeMe::mergeSort() {
    std::cout << "Before:	";
    for (std::vector<int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
	double timeBefore = timeNow();
	merge<std::vector<std::vector<int> >, std::vector<int> >(vectorContainer, 1);
    std::cout << "After:	";
    for (std::vector<int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
	double timeDiff = timeNow() - timeBefore;
	std::cout << "Time to process a range of " << vectorContainer.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeDiff << std::endl;
	timeBefore = timeNow();
	merge<std::deque<std::deque<int> >, std::deque<int> >(dequeContainer, 1);
	timeDiff = timeNow() - timeBefore;
	std::cout << "Time to process a range of " << dequeContainer.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << timeDiff << std::endl;
	if (std::is_sorted(vectorContainer.begin(), vectorContainer.end()))
		std::cout << "vectorContainer -> Sorted!\n";
	else 
		std::cout << "vectorContainer -> Not Sorted!\n";
	if (std::is_sorted(dequeContainer.begin(), dequeContainer.end()))
	// struct timeval tv1,tv2;
		std::cout << "dequeContainer -> Sorted!\n";
	else 
		std::cout << "dequeContainer -> Not Sorted!\n";
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