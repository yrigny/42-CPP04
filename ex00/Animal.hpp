/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:53:18 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/17 16:58:06 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class	Animal {

	protected:

		std::string	type;

	public:

		Animal();
		Animal(const Animal& src);
		Animal&	operator=(const Animal& src);
		~Animal();

		void	makeSound();
};

#endif