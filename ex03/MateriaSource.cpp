/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:55:39 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 18:41:42 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	if (!QUIET)
		std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	if (!QUIET)
		std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->source[i] = NULL;
	*this = src;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& src) {
	if (!QUIET)
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->source[i]) {
			delete this->source[i];
			this->source[i] = NULL;
		}
		if (src.source[i])
			this->source[i] = src.source[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->source[i])
			delete this->source[i];
	}
	if (!QUIET)
		std::cout << "MateriaSource default destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->source[i] && m) {
			this->source[i] = m;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->source[i]->getType() == type)
			return this->source[i]->clone();
	}
	return 0;
}
