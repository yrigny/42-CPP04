/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:41:40 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 20:40:45 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << YELLOW "Cat" NONE " default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	Animal::setType("Cat");
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << YELLOW "Cat" NONE " copy constructor called" << std::endl;
	*this = src;
	this->type = "Cat";
	Animal::setType("Cat");
}

Cat&	Cat::operator=(const Cat& src) {
	std::cout << YELLOW "Cat" NONE " copy assignment operator called" << std::endl;
	this->type = src.type;
	this->brain = src.brain;
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << YELLOW "Cat" NONE " default destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

void	Cat::thinkAloud() const {
	std::cout << this->brain->randomIdea() << std::endl;
}
