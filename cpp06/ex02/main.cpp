/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:10:10 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/20 14:04:30 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:  return new A;
		case 1:  return new B;
		default: return new C;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try { (void)dynamic_cast<A &>(p); std::cout << "A" << std::endl; return; } catch (...) {}
	try { (void)dynamic_cast<B &>(p); std::cout << "B" << std::endl; return; } catch (...) {}
	try { (void)dynamic_cast<C &>(p); std::cout << "C" << std::endl; return; } catch (...) {}
	std::cout << "Unknown" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 5; ++i)
    {
        Base *p = generate();
        std::cout << "ptr: "; identify(p);
        std::cout << "ref: "; identify(*p);
        delete p;
    }
    identify(static_cast<Base *>(NULL));
    return 0;
}
