/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:07:14 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 17:50:01 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include <string>

class	Ice : public AMateria {

	public:

		Ice();
		Ice(const Ice& src);
		~Ice();
		Ice&	operator=(const Ice& src);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
