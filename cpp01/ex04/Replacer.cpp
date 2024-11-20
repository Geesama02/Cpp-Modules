/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:38:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/19 10:30:36 by oait-laa         ###   ########.fr       */
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
	std::ifstream f_read(filename.c_str());
	if (!f_read)
	{
		std::cerr << "Failed to open file to read!\n";
		return (1);
	}
	std::ofstream f_write((filename + ".replace").c_str());
	if (!f_write)
	{
		f_read.close();
		std::cerr << "Failed to open file to write!\n";
		return (1);
	}
	if(!std::getline(f_read, line, '\0'))
	{
		std::cerr << "Failed to read lines!\n";
		f_read.close();
		f_write.close();
		return (1);
	}
	index = line.find(s1);
	while (index != std::string::npos)
	{
		if (s1.empty())
			break;
		line.erase(index, s1.length());
		line.insert(index, s2);
		index = line.find(s1, index + s2.length());
	}
	f_write << line;
	f_read.close();
	f_write.close();
	return (0);
}
