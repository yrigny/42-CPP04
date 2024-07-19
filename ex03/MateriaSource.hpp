/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:43:53 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 19:02:16 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>

class	MateriaSource : public IMateriaSource {

	protected:

		AMateria*	source[4];

	public:

		MateriaSource();
		MateriaSource(const MateriaSource& src);
		~MateriaSource();
		MateriaSource&	operator=(const MateriaSource& src);

		void 		learnMateria(AMateria*);
		AMateria* 	createMateria(std::string const & type);
};

#endif
