/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 13:55:52 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/07 12:11:40 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

template <typename T>
static void	print(T const &container, std::string const &name) {
	std::cout << name << ": [";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "]" << std::endl;
}

template <typename T>
static void	test(T &container, int value, std::string const &name) {
	std::cout << name << " -> search " << value << ": ";
	try
	{
		typename T::iterator	it = easyfind(container, value);
		std::cout << "found " << *it
			<< " at position " << std::distance(container.begin(), it) << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main() {
    std::vector<int>    vec;
    std::list<int>      lst;
    std::deque<int>     deq;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i*10);
        lst.push_back(i*2);
        deq.push_front(i);
    }

	std::cout << "--- vector ---" << std::endl;
	print(vec, "vector");
	test(vec, 30, "vector");
	test(vec, 42, "vector");
   	std::cout << std::endl;

	std::cout << "--- list ---" << std::endl;
	print(lst, "list");
	test(lst, 8, "list");
	test(lst, 3, "list");
   	std::cout << std::endl;

   	std::cout << "--- deque ---" << std::endl;
	print(deq, "deque");
	test(deq, 0, "deque");
	test(deq, -1, "deque");
   	std::cout << std::endl;

	std::cout << "--- duplicates: returns the FIRST match ---" << std::endl;
	vec.push_back(10);
	print(vec, "vector");
	test(vec, 10, "vector");
   	std::cout << std::endl;

	std::cout << "--- returned iterator is usable (modify through it) ---" << std::endl;
	print(vec, "before");
	*easyfind(vec, 20) = 21;
	print(vec, "after");
	test(vec, 21, "vector");
   	std::cout << std::endl;

	std::cout << "--- const container ---" << std::endl;
	std::vector<int> const	cvec(vec);
	// cvec.push_back(1);
	// cvec[0] = 5;
	print(cvec, "const vector");
	try
	{
		std::vector<int>::const_iterator	it = easyfind(cvec, 40);
		std::cout << "const vector -> found " << *it << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
   	std::cout << std::endl;

	std::cout << "--- empty container ---" << std::endl;
	std::vector<int>	empty;
	print(empty, "empty vector");
	test(empty, 0, "empty vector");
   	std::cout << std::endl;

    return (0);
}