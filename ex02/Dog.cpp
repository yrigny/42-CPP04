/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 18:56:15 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << BLUE "Dog" NONE " default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	Animal::setType("Dog");
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << BLUE "Dog" NONE " copy constructor called" << std::endl;
	this->brain = NULL;
	*this = src;
	this->type = "Dog";
	Animal::setType("Dog");
}

Dog&	Dog::operator=(const Dog& src) {
	std::cout << BLUE "Dog" NONE " copy assignment operator called" << std::endl;
	this->type = src.type;
	if (this->brain) {
		delete this->brain;
		this->brain = NULL;
	}
	this->brain = new Brain(*src.brain);
	return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << BLUE "Dog" NONE " default destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

void	Dog::thinkAloud() const {
	std::cout << this->brain->randomIdea() << std::endl;
}
