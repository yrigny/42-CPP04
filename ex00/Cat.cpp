/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:41:40 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 14:30:55 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	Animal::setType("Cat");
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	this->type = "Cat";
	Animal::setType("Cat");
}

Cat&	Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = src.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
