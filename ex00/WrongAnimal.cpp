/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:17 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:18:59 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "Default";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Mysterious animal footsteps..." << std::endl;
}

void	WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}
