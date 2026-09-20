/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:02:41 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/09/20 14:04:30 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data d;
    d.id = 42;
    d.name = "ghenriqu";

    uintptr_t   raw = Serializer::serialize(&d);
    Data        *ptr = Serializer::deserialize(raw);

	std::cout << "original : " << &d << std::endl;
	std::cout << "raw      : 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "restored : " << ptr << std::endl;
	std::cout << (ptr == &d ? "OK" : "FAIL") << " -> " << ptr->id << " " << ptr->name << std::endl;
	return 0;
}
