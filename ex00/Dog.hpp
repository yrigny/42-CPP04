/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:45:45 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:12:45 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class	Dog : public Animal {

	public:

		Dog();
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);
		~Dog();

		void		makeSound() const;
};

#endif
