/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:38:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/18 15:39:20 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string fname)
{
	filename = fname;
}
int	Replacer::replace(std::string s1, std::string s2)
{
	std::ifstream f_read;
	std::ofstream f_write;
	std::string line;
	size_t index;
	f_read.open(filename);
	f_write.open(filename + ".replace");
	while (std::getline(f_read, line))
	{
		index = line.find(s1);
		while (index != std::string::npos)
		{
			line.erase(index, s1.length());
			line.insert(index, s2);
			index = line.find(s1);
		}
		f_write << line;
		if (!f_read.eof())
			f_write << '\n';
	}
	return (0);
}