/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:39:30 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:31:09 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat : public Animal {

	private:

		std::string	type;

	public:

		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);
		~Cat();

		void		makeSound() const;
};

#endif
