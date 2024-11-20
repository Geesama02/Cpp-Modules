/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:32:13 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/19 10:34:32 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Must Be Three Parameters!\n";
		return (1);
	}
	Replacer my_replacer(argv[1]);
	if (my_replacer.replace(argv[2], argv[3]))
		return (1);
	return (0);
}
