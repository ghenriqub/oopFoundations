/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:04:26 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 18:04:28 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "===== Polymorphism (Animal is abstract: cannot instantiate) =====" << std::endl;
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << "Cat type: " << i->getType() << " | sound: ";
	i->makeSound();
	std::cout << "Dog type: " << j->getType() << " | sound: ";
	j->makeSound();
	delete i;
	delete j;

	std::cout << std::endl << "===== WrongAnimal: makeSound is not virtual =====" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << "WrongAnimal* -> WrongCat: ";
	wi->makeSound();
	std::cout << "WrongAnimal* -> WrongAnimal: ";
	wmeta->makeSound();
	delete wmeta;
	delete wi;

	std::cout << std::endl << "===== Deep copy test =====" << std::endl;
	Cat* cat1 = new Cat();
	cat1->getBrain()->setIdea(0, "I want to catch a mouse");

	Cat* cat2 = new Cat(*cat1);
	std::cout << "cat1 brain[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2 brain[0]: " << cat2->getBrain()->getIdea(0) << std::endl;

	cat1->getBrain()->setIdea(0, "I changed my mind");
	std::cout << "After modifying cat1:" << std::endl;
	std::cout << "cat1 brain[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2 brain[0]: " << cat2->getBrain()->getIdea(0) << std::endl;
	if (cat2->getBrain()->getIdea(0) == "I want to catch a mouse")
		std::cout << "Deep copy confirmed: cat2 was not affected" << std::endl;
	else
		std::cout << "SHALLOW COPY DETECTED: cat2 was affected!" << std::endl;

	delete cat1;
	delete cat2;

	return 0;
}
