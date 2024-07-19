/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:07:14 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 19:01:59 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include <string>

class	Cure : public AMateria {

	public:

		Cure();
		Cure(const Cure& src);
		~Cure();
		Cure&	operator=(const Cure& src);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
