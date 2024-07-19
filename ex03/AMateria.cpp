/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:13:27 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 19:56:47 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("default") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "AMateria default constructor called with type " << type << std::endl;
}

AMateria::AMateria(const AMateria& src) {
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria&	AMateria::operator=(const AMateria& src) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria default destructor called" << std::endl;
}

std::string const&	AMateria::getType() const {
	return this->type;
}

void	AMateria::use(ICharacter& target) {
	static_cast<void>(target);
}