/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:50:40 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/01/17 16:35:48 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	N = 5;

	Zombie*	horde = zombieHorde(N, "Foo");

	if (horde) {
		for (int i = 0; i < N; i++) {
			horde[i].announce();
		}
		delete[] horde;
	}
	return 0;
}
