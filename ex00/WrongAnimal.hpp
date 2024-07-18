/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:06 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:29:04 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>

class	WrongAnimal {

	protected:

		std::string	type;

	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal&	operator=(const WrongAnimal& src);
		virtual			~WrongAnimal();

		void			makeSound() const;
		void			setType(std::string type);
		std::string		getType() const;
};

#endif
