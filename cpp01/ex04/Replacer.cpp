/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:38:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/18 15:51:00 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string fname)
{
	filename = fname;
}
int	Replacer::replace(std::string s1, std::string s2)
{
	std::string line;
	size_t index;
	std::ifstream f_read(filename);
	if (!f_read)
	{
		std::cerr << "Failed to open file to read!\n";
		return (1);
	}
	std::ofstream f_write(filename + ".replace");
	if (!f_write)
	{
		std::cerr << "Failed to open file to write!\n";
		return (1);
	}
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
	f_read.close();
	f_write.close();
	return (0);
}
