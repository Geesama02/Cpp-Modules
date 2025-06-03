/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:36:54 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/03 10:46:03 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    std::list<int> mlist;
    mstack.push(5);
    mlist.push_back(5);
    mstack.push(17);
    mlist.push_back(17);
    std::cout << "MutantStack last element -> " << mstack.top() << std::endl;
    std::cout << "List last element -> " << mlist.back() << std::endl;
    mstack.pop();
    mlist.pop_back();
    std::cout << "MutantStack size -> " << mstack.size() << std::endl;
    std::cout << "List size -> " << mlist.size() << std::endl;
    mstack.push(3);
    mlist.push_back(3);
    mstack.push(5);
    mlist.push_back(5);
    mstack.push(737);
    mlist.push_back(737);
    mstack.push(0);
    mlist.push_back(0);
    std::cout << "MutantStack size -> " << mstack.size() << std::endl;
    std::cout << "List size -> " << mlist.size() << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::list<int>::iterator l_it = mlist.begin();
    std::list<int>::iterator l_ite = mlist.end();
    ++it;
    ++l_it;
    if (it == it)
        std::cout << "Equal iterators!" << std::endl;
    else
        std::cout << "Not Equal!" << std::endl;
    if (l_it == l_it)
        std::cout << "Equal iterators!" << std::endl;
    else
        std::cout << "Not Equal!" << std::endl;
    --it;
    --l_it;
    std::cout << "MutantStack Elements: " << "{ ";
    while (it != ite)
    {
        std::cout << *it;
        ++it;
        if (it != ite)
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
    std::cout << "List Elements: " << "{ ";
    while (l_it != l_ite)
    {
        std::cout << *l_it;
        ++l_it;
        if (l_it != l_ite)
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
    MutantStack<int> mstack2 = mstack;
    std::stack<int> s(mstack);
    return 0;
}