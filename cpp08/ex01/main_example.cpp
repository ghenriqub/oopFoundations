/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_example.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:25:29 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/07 13:37:23 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

template <typename T>
static void	print(T const &container, std::string const &name, std::size_t limit = 20) {
	std::size_t	shown = 0;

	std::cout << name << ": [";
	for (typename T::const_iterator it = container.begin();
		it != container.end() && shown < limit; ++it, ++shown)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	if (container.size() > limit)
		std::cout << ", ... (" << container.size() << " total)";
	std::cout << "]" << std::endl;
}

int	main(void)
{
	std::cout << "--- 1. subject test ---" << std::endl;
	{
		int const			values[] = {6, 3, 17, 9, 11};
		std::vector<int>	input(values, values + 5);
		Span				sp = Span(5);

		for (std::size_t i = 0; i < input.size(); i++)
			sp.addNumber(input[i]);
		print(input, "input");
		std::sort(input.begin(), input.end());
		print(input, "sorted");
		std::cout << "shortest: " << sp.shortestSpan() << "   (11 - 9: closest neighbours after sorting)" << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << "  (17 - 3: max - min)" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- 2. exceptions ---" << std::endl;
	{
		Span	sp(2);

		std::cout << "Span(2), empty -> shortestSpan(): ";
		try { sp.shortestSpan(); }
		catch (std::exception const &e) { std::cout << e.what() << std::endl; }

		sp.addNumber(1);
		std::cout << "Span(2), [1] -> longestSpan(): ";
		try { sp.longestSpan(); }
		catch (std::exception const &e) { std::cout << e.what() << std::endl; }

		sp.addNumber(2);
		std::cout << "Span(2), [1, 2] -> addNumber(3): ";
		try { sp.addNumber(3); }
		catch (std::exception const &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << std::endl;

	std::cout << "--- 3. 10000 random numbers in ONE call (addNumbers) ---" << std::endl;
	{
		std::vector<int>	source;

		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			source.push_back(std::rand());
		print(source, "source", 5);

		Span	sp(10000);
		sp.addNumbers(source.begin(), source.end());
		std::cout << "shortest: " << sp.shortestSpan() << "   (0 is valid: duplicates can happen)" << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- 4. addNumbers from a std::list + range too big ---" << std::endl;
	{
		std::list<int>	lst;

		for (int i = 0; i < 5; i++)
			lst.push_back(i * i);
		print(lst, "list");

		Span	sp(7);
		sp.addNumbers(lst.begin(), lst.end());
		std::cout << "Span(7) after adding the list: 5 used, 2 free" << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << "   (1 - 0)" << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << "  (16 - 0)" << std::endl;
		std::cout << "adding the same 5 numbers again: ";
		try { sp.addNumbers(lst.begin(), lst.end()); }
		catch (std::exception const &e) { std::cout << e.what() << std::endl; }
		// If any number had been inserted, a duplicate would make the shortest span 0.
		std::cout << "nothing was inserted: shortest still " << sp.shortestSpan()
			<< "   (duplicates would have made it 0)" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- 5. extremes: INT_MIN / INT_MAX (no overflow) ---" << std::endl;
	{
		int const			values[] = {INT_MIN, INT_MAX, 0};
		std::vector<int>	input(values, values + 3);
		Span				sp(3);

		sp.addNumbers(input.begin(), input.end());
		print(input, "input");
		std::cout << "shortest: " << sp.shortestSpan() << "   (INT_MAX - 0)" << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << "  (INT_MAX - INT_MIN, does not fit in int)" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- 6. copy constructor and assignment are deep ---" << std::endl;
	{
		std::vector<int>	values;
		values.push_back(10);
		values.push_back(20);

		Span	a(3);
		a.addNumbers(values.begin(), values.end());

		Span	b(a);		// copy constructor
		Span	c;			// default constructor (capacity 0)
		c = a;				// assignment operator
		b.addNumber(21);
		c.addNumber(12);

		print(values, "a");
		std::cout << "b = copy of a, then addNumber(21): [10, 20, 21]" << std::endl;
		std::cout << "c = a (assignment), then addNumber(12): [10, 20, 12]" << std::endl;
		std::cout << "a shortest: " << a.shortestSpan() << "  (unchanged: 20 - 10)" << std::endl;
		std::cout << "b shortest: " << b.shortestSpan() << "   (21 - 20)" << std::endl;
		std::cout << "c shortest: " << c.shortestSpan() << "   (12 - 10)" << std::endl;
	}
	return (0);
}
