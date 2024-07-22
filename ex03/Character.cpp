/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:53:09 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 18:42:04 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("default") {
	if (!QUIET)
		std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(std::string name) : name(name) {
	if (!QUIET)
		std::cout << "Character default constructor called with name " << name << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(const Character& src) {
	if (!QUIET)
		std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
	*this = src;
}

Character&	Character::operator=(const Character& src) {
	if (!QUIET)
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
	if (!QUIET)
		std::cout << "Character default destructor called" << std::endl;
}

std::string const&	Character::getName() const {
	return this->name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->slot[i] && this->slot[i] == m) {
			if (!QUIET)
				std::cerr << "* cannot reequip the same Materia object *" << std::endl;
			return;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (m && !this->slot[i]) {
			this->slot[i] = m;
			if (!QUIET)
				std::cout << "* a new " << m->getType() << " is equipped *" << std::endl;
			return;
		}
	}
	if (m)
		this->dropMateria(m);
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->slot[idx]) {
		this->slot[idx] = NULL;
		return;
	}
	if (!QUIET)
		std::cout << "* cannot unequip something inexistent *" << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->slot[idx]) {
		this->slot[idx]->use(target);
		delete this->slot[idx];
		this->slot[idx] = NULL;
		return;
	}
	if (!QUIET)
		std::cout << "* cannot use something inexistent *" << std::endl;
}

void	Character::dropMateria(AMateria* object) {
	for (int i = 0; i < 1024; i++) {
		if (!floor[i] && object) {
			floor[i] = object;
			std::cout << "* drops a " << floor[i]->getType() << " on the floor *" << std::endl;
			return;
		}
	}
}

void	Character::dropMateria(int idx) {
	if (idx >= 0 && idx < 4 && this->slot[idx]) {
		dropMateria(this->slot[idx]);
		return;
	}
	if (!QUIET)
		std::cout << "* cannot drop something inexistent *" << std::endl;
}
