/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:58:20 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:49:53 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Default";
}

Animal::Animal(const Animal& src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal&	Animal::operator=(const Animal& src) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Mysterious animal footsteps..." << std::endl;
}

void	Animal::setType(std::string type) {
	this->type = type;
}

std::string	Animal::getType() const {
	return this->type;
}
