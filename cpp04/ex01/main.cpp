/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:08:44 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 16:13:10 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Cat l;
	Cat k;
	Dog x;
	std::cout << "===========================\n";
	Animal *test = new Dog(x);
	(void)test;
	std::cout << "===========================\n";
	k = l;
	std::cout << "===========================\n";
	Animal *array[6];
	int n = 0;
	while (n < 6)
	{
		if (n < 3)
			array[n] = new Dog();
		else
			array[n] = new Cat();
		n++;
	}
	n = 0;
	std::cout << "===========================\n";
	while(n < 6)
	{
		delete array[n];
		n++;
	}
	delete test;
	delete i;
	delete j;
	return (0);
}
