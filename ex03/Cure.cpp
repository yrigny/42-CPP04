/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:15:48 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 18:02:28 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() {
	std::cout << "Cure default constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure& src) {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure&	Cure::operator=(const Cure& src) {
	std::cout << "Cure copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure default destructor called" << std::endl;
}

AMateria*	Cure::clone() const {
	AMateria*	copy = new Cure(*this);
	return copy;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
