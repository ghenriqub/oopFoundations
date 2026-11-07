/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:42:20 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/07 13:56:20 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

// Prints any iterable container as: name: [a, b, c]
// For MutantStack the order is bottom -> top (begin() = first pushed).
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

int	main(void)
{
	std::cout << "--- 1. subject test (MutantStack) ---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int>	s(mstack);
	}
	std::cout << std::endl;

	std::cout << "--- 2. same test with std::list (output must match) ---" << std::endl;
	{
		std::list<int>	lst;

		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator	it = lst.begin();
		std::list<int>::iterator	ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;

	std::cout << "--- 3. step by step: the stack state after each operation ---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		print(mstack, "push(5)    ");
		mstack.push(17);
		print(mstack, "push(17)   ");
		std::cout << "top()      = " << mstack.top() << "   (last pushed)" << std::endl;
		mstack.pop();
		print(mstack, "pop()      ");
		std::cout << "size()     = " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		print(mstack, "push x4    ");
		std::cout << "top()      = " << mstack.top() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- 4. automatic comparison with std::list (std::equal) ---" << std::endl;
	{
		MutantStack<int>	mstack;
		std::list<int>		lst;
		int const			values[] = {5, 3, 5, 737, 0};

		for (int i = 0; i < 5; i++)
		{
			mstack.push(values[i]);
			lst.push_back(values[i]);
		}
		print(mstack, "MutantStack");
		print(lst, "std::list  ");
		std::cout << "same size and same elements in the same order: "
			<< (mstack.size() == lst.size() && std::equal(mstack.begin(), mstack.end(), lst.begin())
				? "yes" : "no") << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- 5. iterators: both directions + STL algorithms ---" << std::endl;
	{
		MutantStack<int>	mstack;

		for (int i = 1; i <= 5; i++)
			mstack.push(i * 10);
		print(mstack, "forward  (bottom -> top)");

		std::cout << "reverse  (top -> bottom): [";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		{
			if (it != mstack.rbegin())
				std::cout << ", ";
			std::cout << *it;
		}
		std::cout << "]   (= order pop() would remove them)" << std::endl;

		MutantStack<int>::iterator	it = mstack.end();
		--it;
		std::cout << "--end()  = " << *it << "   (bidirectional: can go backwards)" << std::endl;

		std::cout << "std::find(30)       -> position "
			<< std::distance(mstack.begin(), std::find(mstack.begin(), mstack.end(), 30)) << std::endl;
		std::cout << "std::accumulate     -> sum " << std::accumulate(mstack.begin(), mstack.end(), 0) << std::endl;
		std::cout << "*std::max_element   -> " << *std::max_element(mstack.begin(), mstack.end()) << std::endl;

		*mstack.begin() = 99;	// iterators also allow writing
		print(mstack, "after *begin() = 99     ");
	}
	std::cout << std::endl;

	std::cout << "--- 6. canonical form: copies are deep ---" << std::endl;
	{
		MutantStack<int>	a;
		a.push(1);
		a.push(2);

		MutantStack<int>		b(a);	// copy constructor
		MutantStack<int>		c;		// default constructor
		c = a;							// assignment operator
		b.push(3);
		c.pop();

		MutantStack<int> const	d(a);	// const copy: only const_iterator is available
		print(a, "a                ");
		print(b, "b = copy, push(3)");
		print(c, "c = a, pop()     ");
		print(d, "d (const)        ");
	}
	std::cout << std::endl;

	std::cout << "--- 7. other underlying containers and types ---" << std::endl;
	{
		MutantStack<std::string, std::vector<std::string> >	words;
		words.push("hello");
		words.push("42");
		words.push("Porto");
		print(words, "MutantStack<string, vector>");

		MutantStack<int, std::list<int> >	linked;
		linked.push(1);
		linked.push(2);
		print(linked, "MutantStack<int, list>     ");
	}
	std::cout << std::endl;

	std::cout << "--- 8. MutantStack IS a std::stack (public inheritance) ---" << std::endl;
	{
		MutantStack<int>	mstack;
		mstack.push(7);
		mstack.push(8);

		std::stack<int>	s(mstack);	// copies the std::stack part
		std::cout << "std::stack copy: top() = " << s.top() << ", size() = " << s.size()
			<< "   (no iterators: std::stack hides them)" << std::endl;
	}
	return (0);
}
