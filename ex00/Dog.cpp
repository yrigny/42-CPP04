/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:30:36 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	Animal::setType("Dog");
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	this->type = "Dog";
	Animal::setType("Dog");
}

Dog&	Dog::operator=(const Dog& src) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
