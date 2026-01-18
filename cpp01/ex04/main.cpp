/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:07:54 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/18 17:41:41 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./replacer [file.txt] [occurence] [replace]" << std::endl;
		return 1;
	}

	std::string		filename(argv[1]);
	std::string		firstStr(argv[2]);
	std::string		secondStr(argv[3]);

	if (firstStr.empty()) {
		std::cerr << "Error: search string cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream	infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: cannot open file '" << filename << "'" << std::endl;
		return 1;
	}

	std::string		newFilename = filename + ".replace";
	std::ofstream	outfile(newFilename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: cannot create file '" << newFilename << "'" << std::endl;
		infile.close();
		return 1;
	}

	std::string		line;
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
