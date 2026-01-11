/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:38:36 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/11 18:07:25 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;
	randomChump("Bar");
	return 0;
}
