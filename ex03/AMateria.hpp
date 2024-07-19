/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:27:52 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 20:16:24 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP
# include "ICharacter.hpp"
# include <string>

class	ICharacter;

class	AMateria {

	protected:

		std::string	type;

	public:

		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& src);
		virtual	~AMateria();
		AMateria&	operator=(const AMateria& src);

		std::string const&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

typedef struct	s_list {

	void*			content;
	struct s_list*	next;

}				t_slist;


#endif