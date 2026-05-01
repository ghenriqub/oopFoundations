/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:58:49 by nogioni-          #+#    #+#             */
/*   Updated: 2026/02/16 19:31:50 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========= Creating an Animal, a Cat and a Dog =========" << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	std::cout << "========= Getting Types =========" << std::endl;
	std::cout << "Cat: " << i->getType() << std::endl;
	std::cout << "Dog: " << j->getType() << std::endl;
	std::cout << "Animal: " << meta->getType() << std::endl;
	
	std::cout << "========= Making Sounds =========" << std::endl;
	std::cout << "Cats go: ";
	i->makeSound();
	std::cout << "Dogs go: ";
	j->makeSound();
	std::cout << "Animals go: ";
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "========= Testing WrongAnimal and WrongCat =========" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();

	std::cout << "WrongCat: " << wi->getType() << std::endl;
	wi->makeSound();
	std::cout << "WrongAnimal: " << wmeta->getType() << std::endl;
	wmeta->makeSound();
	std::cout << std::endl;
	
	std::cout << "========= Deleting Objects =========" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wmeta;
	delete wi;

	return 0;
}