/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:15:48 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 18:37:42 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
	if (!QUIET)
		std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& src) {
	if (!QUIET)
		std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice&	Ice::operator=(const Ice& src) {
	if (!QUIET)
		std::cout << "Ice copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

Ice::~Ice() {
	if (!QUIET)
		std::cout << "Ice default destructor called" << std::endl;
}

AMateria*	Ice::clone() const {
	AMateria*	copy = new Ice(*this);
	return copy;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
