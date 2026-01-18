/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:07:54 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/18 17:15:28 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int	main(int argc, char **argv) {
	std::string		line;
	std::string		filename(argv[1]);
	std::string		firstStr(argv[2]);
	std::string		secondStr(argv[3]);

	if (argc != 4 || !argv[2] || !argv[3]) {
		std::cerr << "Usage: [file.txt] [occurence] [replace]" << std::endl;
		return 1;
	}
	std::ifstream	infile(filename.c_str());
	if (!infile.good()) {
		std::cout << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}
	std::string		newFilename = filename.append(".replace");
	std::ofstream	outfile(newFilename.c_str());
	if (!outfile.good()) {
		std::cout << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}
	while (std::getline(infile, line)) {
		std::size_t	pos = 0;
		while ((pos = line.find(firstStr, pos)) != std::string::npos) {
			line.erase(pos, firstStr.length());
			line.insert(pos, secondStr);
			pos += secondStr.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
