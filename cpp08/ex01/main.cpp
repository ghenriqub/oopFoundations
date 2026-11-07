/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:21:48 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/07 13:24:57 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>

int	main(void)
{
	std::cout << "--- subject test ---" << std::endl;
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "--- exceptions ---" << std::endl;
	{
		Span	sp(2);

		try { sp.shortestSpan(); }
		catch (std::exception const &e) { std::cout << "empty: " << e.what() << std::endl; }
		sp.addNumber(1);
		try { sp.longestSpan(); }
		catch (std::exception const &e) { std::cout << "one number: " << e.what() << std::endl; }
		sp.addNumber(2);
		try { sp.addNumber(3); }
		catch (std::exception const &e) { std::cout << "full: " << e.what() << std::endl; }
		std::cout << std::endl;
	}

	std::cout << "--- 10000 random numbers via addNumbers ---" << std::endl;
	{
		std::srand(std::time(NULL));
		std::vector<int>	source;
		for (int i = 0; i < 10000; i++)
			source.push_back(std::rand());

		Span	sp(10000);
		sp.addNumbers(source.begin(), source.end());
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- addNumbers from a list + range too big ---" << std::endl;
	{
		std::list<int>	lst;
		for (int i = 0; i < 5; i++)
			lst.push_back(i * i);

		Span	sp(7);
		sp.addNumbers(lst.begin(), lst.end());
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
		try { sp.addNumbers(lst.begin(), lst.end()); }
		catch (std::exception const &e) { std::cout << e.what() << std::endl; }
		std::cout << std::endl;
	}

	std::cout << "--- extremes: INT_MIN / INT_MAX (no overflow) ---" << std::endl;
	{
		Span	sp(3);

		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		sp.addNumber(0);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- copy is deep ---" << std::endl;
	{
		Span	a(3);
		a.addNumber(10);
		a.addNumber(20);

		Span	b(a);
		b.addNumber(27);
		std::cout << "a shortest: " << a.shortestSpan() << std::endl;
		std::cout << "b shortest: " << b.shortestSpan() << std::endl;
		std::cout << std::endl;
	}

    return (0);
}
