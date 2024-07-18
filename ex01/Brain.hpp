/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:14:18 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 18:43:34 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>

class Brain {

	private:
	
		std::string*	ideas;

	public:

		Brain();
		Brain(const Brain& src);
		Brain&	operator=(const Brain& src);
		~Brain();

		std::string&	randomIdea();
};

#endif
