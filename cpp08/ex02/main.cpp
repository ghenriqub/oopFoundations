/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:48:27 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/10/31 16:58:31 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>

int	main(void)
{
	std::cout << "--- subject test (MutantStack) ---" << std::endl;
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
		std::cout << std::endl;
	}

	std::cout << "--- same test with std::list (output must match) ---" << std::endl;
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
		std::cout << std::endl;
	}

	std::cout << "--- reverse iteration = stack order (top first) ---" << std::endl;
	{
		MutantStack<int>	mstack;
		for (int i = 1; i <= 3; i++)
			mstack.push(i);
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- const + deep copy ---" << std::endl;
	{
		MutantStack<int>	a;
		a.push(42);

		MutantStack<int> const	b(a);
		a.push(99);
		for (MutantStack<int>::const_iterator it = b.begin(); it != b.end(); ++it)
			std::cout << *it << " ";
		std::cout << "(b size " << b.size() << ", a size " << a.size() << ")" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- other underlying container + other type ---" << std::endl;
	{
		MutantStack<std::string, std::vector<std::string> >	words;
		words.push("hello");
		words.push("42");
		words.push("Porto");
		for (MutantStack<std::string, std::vector<std::string> >::iterator it = words.begin(); it != words.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

    return (0);
}
