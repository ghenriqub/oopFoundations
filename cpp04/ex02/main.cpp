/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:04:26 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 18:28:52 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "========= Creating a Cat and a Dog =========" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;
 
	std::cout << std::endl;

	std::cout << "========= Creating array of Animals =========" << std::endl;
	const int SIZE = 10;
	Animal* animals[SIZE];
	for (int k = 0; k < SIZE / 2; k++)
		animals[k] = new Dog();
	for (int k = SIZE / 2; k < SIZE; k++)
		animals[k] = new Cat();
 
	std::cout << std::endl;

	std::cout << "========= Deleting array =========" << std::endl;
	for (int k = 0; k < SIZE; k++)
		delete animals[k];
 
	std::cout << std::endl;

	std::cout << "========= Deep copy test =========" << std::endl;
	Cat original;
	original.getBrain()->setIdea(0, "I want to catch a mouse");
	Cat copy(original);
	std::cout << "original brain[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "copy     brain[0]: " << copy.getBrain()->getIdea(0) << std::endl;
	original.getBrain()->setIdea(0, "I changed my mind");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "original brain[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "copy     brain[0]: " << copy.getBrain()->getIdea(0) << std::endl;
 
	return 0;
}
