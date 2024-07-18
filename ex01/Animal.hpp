/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:53:18 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 18:56:48 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# define COLOR "\033[0;91m"
# define NONE "\033[0m"
# include <iostream>

class	Animal {

	protected:

		std::string	type;

	public:

		Animal();
		Animal(const Animal& src);
		virtual	~Animal();
		Animal&	operator=(const Animal& src);

		virtual void	makeSound() const;
		void			setType(std::string type);
		std::string		getType() const;
};

#endif
