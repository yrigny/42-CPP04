/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:45:02 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:16:45 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <string>

class	ICharacter;

class	Character : public ICharacter {

	private:

		std::string	name;
		AMateria*	slot[4];

	public:

		static AMateria*	floor[1024];

		Character();
		Character(std::string name);
		Character(const Character& src);
		~Character();
		Character&	operator=(const Character& src);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				dropMateria(AMateria* object);
		void				dropMateria(int idx);
};

#endif
