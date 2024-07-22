/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:20:45 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:12:58 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	public:

		WrongCat();
		WrongCat(const WrongCat& src);
		WrongCat&	operator=(const WrongCat& src);
		~WrongCat();

		void		makeSound() const;
};

#endif
