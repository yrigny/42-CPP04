/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:53:09 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 20:18:36 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("default") {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(std::string name) : name(name) {
	std::cout << "Character default constructor called with name " << name << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(const Character& src) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
	*this = src;
}

Character&	Character::operator=(const Character& src) {
	std::cout << "Character copy assignment operator called" << std::endl;
	this->name = src.getName();
	for (int i = 0; i < 4; i++) {
		if (this->slot[i]) {
			delete this->slot[i];
			this->slot[i] = NULL;
		}
		if (src.slot[i]) {
			this->slot[i] = src.slot[i]->clone();
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->slot[i])
			delete this->slot[i];
	}
	std::cout << "Character default destructor called" << std::endl;
}

std::string const&	Character::getName() const {
	return this->name;
}

void	Character::equip(AMateria* m) {
	bool	already_have = 0;
	for (int i = 0; i < 4; i++) {
		if (this->slot[i] && this->slot[i]->getType() == m->getType()) {
			already_have = 1;
			return;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (m && !this->slot[i]) {
			this->slot[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->slot[idx])
		this->slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (this->slot[idx]) {
		this->slot[idx]->use(target);
		delete this->slot[idx];
		this->slot[idx] = NULL;
	}
}


