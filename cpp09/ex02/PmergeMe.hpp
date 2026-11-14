/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:55:48 by ghenriqu          #+#    #+#             */
/*   Updated: 2026/11/14 18:11:50 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv);

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	fillVector(int argc, char **argv);
		void	fillDeque(int argc, char **argv);
		void	sortVector();
		void	sortDeque();
};

#endif
