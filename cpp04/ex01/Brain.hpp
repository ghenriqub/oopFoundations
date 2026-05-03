/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:01:10 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 19:22:14 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Holds std::string _ideas[100], provides setIdea/getIdea with bounds checking.
// Copy assignment loops all 100 elements for deep copy — this is the resource
// that Dog/Cat must manage.

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif