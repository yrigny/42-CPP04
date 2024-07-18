/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:23:50 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:32:16 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	WrongAnimal::setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	this->type = "WrongCat";
	WrongAnimal::setType("WrongCat");
}

WrongCat&	WrongCat::operator=(const WrongCat& src) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
