/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:56:46 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/26 17:57:42 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& x) {
	std::cout << x << std::endl;
}

void increment(int& x) {
	x++;
}

void toUpper(std::string& s) {
	for (size_t i = 0; i < s.size(); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
}

int main(void) {
	int numbers[] = {1, 2, 3, 4, 5};
	std::string words[] = {"hello", "world", "forty-two"};
	const double constants[] = {3.14, 2.71, 1.41};

	::iter(numbers, 5, print<int>);
	::iter(numbers, 5, increment);
	::iter(numbers, 5, print<int>);

	::iter(words, 3, toUpper);
	::iter(words, 3, print<std::string>);

	::iter(constants, 3, print<double>);

	int* null = NULL;
	::iter(null, 5, increment);
	return 0;
}
