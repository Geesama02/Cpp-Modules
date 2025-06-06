/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:45:22 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/03 09:49:16 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T> {
    public:
        struct iterator
        {
            typename Container::iterator ptr;
            iterator() { ptr = NULL; }
            iterator(typename Container::iterator p) { ptr = p; }
            iterator(const iterator& cpy) { ptr = cpy.ptr; }
            iterator& operator=(const iterator& cpy) {
                if (this != &cpy)
                    ptr = cpy.ptr;
                return (*this);
            };
            bool operator!=(const iterator& other) const {
                return (ptr != other.ptr);
            };
            bool operator==(const iterator& other) const {
                return (ptr == other.ptr);
            };
            T& operator*() { return(*ptr); }
            iterator& operator++() { ptr++; return (*this); }
            iterator operator++(int) { iterator tmp = *this; ptr++; return (tmp); }
            iterator& operator--() { ptr--; return (*this); }
            iterator operator--(int) { iterator tmp = *this; ptr--; return (tmp); }
            ~iterator() {}
        };
        iterator begin() { return (iterator(this->c.begin())); }
        iterator end() { return (iterator(this->c.end())); }
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack& cpy) : std::stack<T>(cpy) {};
        MutantStack& operator=(const MutantStack& cpy) {
            if (this != &cpy)
                std::stack<T>::operator=(cpy);
            return (*this);
        };
        ~MutantStack() {};
};

#endif