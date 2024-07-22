/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:39:30 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:13:11 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# define YELLOW "\033[0;93m"
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {

	private:

		Brain*		brain;

	public:

		Cat();
		Cat(const Cat& src);
		~Cat();
		Cat&	operator=(const Cat& src);

		void	makeSound() const;
		void	thinkAloud() const;
};

#endif
