/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:45:45 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:15:41 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# define BLUE "\033[0;94m"
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {

	private:

		Brain*		brain;

	public:

		Dog();
		Dog(const Dog& src);
		~Dog();
		Dog&	operator=(const Dog& src);

		void	makeSound() const;
		void	thinkAloud() const;
};

#endif
