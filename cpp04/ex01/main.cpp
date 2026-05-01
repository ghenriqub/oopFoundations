/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:58:49 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/01 10:18:29 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << "===== Creating array of 10 Animals =====" << std::endl;
	const int SIZE = 10;
	Animal* animals[SIZE];
	for (int i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat();

	std::cout << std::endl << "===== Deleting array =====" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete animals[i];

	std::cout << std::endl << "===== Deep copy test =====" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I like bones");

	Dog copy(original);
	std::cout << "original brain[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "copy    brain[0]: " << copy.getBrain()->getIdea(0) << std::endl;

	original.getBrain()->setIdea(0, "I like sticks now");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "original brain[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "copy    brain[0]: " << copy.getBrain()->getIdea(0) << std::endl;
	if (copy.getBrain()->getIdea(0) == "I like bones")
		std::cout << "Deep copy confirmed: copy was not affected" << std::endl;
	else
		std::cout << "SHALLOW COPY DETECTED: copy was affected!" << std::endl;

	return 0;
}
