/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:26:04 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:20:13 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#define GREEN "\033[1;32m"
#define FADE "\033[2m"
#define NONE "\033[0m"

AMateria*	Character::floor[1024] = {NULL};

int	main() {
	{
		// test provided by the subject
		std::cout << std::endl << GREEN "Test provided by the subject" NONE << std::endl;
		
		std::cout << std::endl;
		// create a Materia Source, and learn Materia 'Ice' and Materia 'Cure'
		std::cout << FADE "create MateriaSource 'src'" NONE << std::endl;
		IMateriaSource* src = new MateriaSource();
		std::cout << FADE "MateriaSource 'src' learn Materia 'ice'" NONE << std::endl;
		src->learnMateria(new Ice());
		std::cout << FADE "MateriaSource 'src' learn Materia 'cure'" NONE << std::endl;
		src->learnMateria(new Cure());

		std::cout << std::endl;
		// create Character 'me' and equip it
		std::cout << FADE "create Character 'me'" NONE << std::endl;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << FADE "equip 'me' with a new 'ice' in slot[0]" NONE << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << FADE "equip 'me' with a new 'cure' in slot[1]" NONE << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);

		std::cout << std::endl;
		// create Character 'bob' with no equipment
		std::cout << FADE "create Character 'bob' and equip with nothing" NONE << std::endl;
		ICharacter* bob = new Character("bob");

		std::cout << std::endl;
		// test normal usage of existing equipment
		std::cout << FADE "Character 'me' use slot[0] (ice) on Character 'bob'" NONE << std::endl;
		me->use(0, *bob);
		std::cout << FADE "Character 'me' use slot[1] (cure) on Character 'bob'" NONE << std::endl;
		me->use(1, *bob);

		std::cout << std::endl;	
		// delete allocated memory
		std::cout << FADE "delete Character 'bob' (nothing left in slot)" NONE << std::endl;
		delete bob;
		std::cout << FADE "delete Character 'me' (nothing left in slot)" NONE << std::endl;
		delete me;
		std::cout << FADE "delete MateriaSource 'src' (with ice and cure learned)" NONE << std::endl;
		delete src;
	}
	{
		// extra test 1 - copy constructors & materias left on the floor
		std::cout << std::endl << GREEN "Extra test 1 - copy constructors & materias left on the floor" NONE << std::endl;

		std::cout << std::endl;
		// create a Materia Source, and learn Materia 'Ice' and Materia 'Cure'
		std::cout << FADE "create MateriaSource 'src'" NONE << std::endl;
		IMateriaSource* src = new MateriaSource();
		std::cout << FADE "MateriaSource 'src' learn Materia 'ice'" NONE << std::endl;
		src->learnMateria(new Ice());
		std::cout << FADE "MateriaSource 'src' learn Materia 'cure'" NONE << std::endl;
		src->learnMateria(new Cure());

		std::cout << std::endl;
		// create Character 'me' and equip it
		std::cout << FADE "create Character 'me'" NONE << std::endl;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << FADE "equip 'me' with a new 'cure' in slot[0]" NONE << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << FADE "equip 'me' with a new 'ice' in slot[1]" NONE << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		
		std::cout << std::endl;
		// test copy construct 'bob' with 'me' (Character <- Materia)
		std::cout << FADE "create Character 'bob' copying Character 'me' (with slot: cure, ice, none, none)" NONE << std::endl;
		ICharacter* bob = new Character(*(Character*)me);

		std::cout << std::endl;
		// test dropMateria() and unequip() functions
		std::cout << FADE "Character 'me' drops and unequips slot[0] (cure)" NONE << std::endl;
		((Character*)me)->dropMateria(0);
		me->unequip(0);
		std::cout << FADE "Character 'me' try to use slot[0] (already unequipped)" NONE << std::endl;
		me->use(0, *bob);
		std::cout << FADE "Character 'me' drops and unequips slot[2] (none)" NONE << std::endl;
		((Character*)me)->dropMateria(2);
		me->unequip(2);
		std::cout << FADE "Character 'bob' drops and unequips its slot[10] (out of range)" NONE << std::endl;
		((Character*)bob)->dropMateria(10);
		bob->unequip(10);

		std::cout << std::endl;	
		// delete allocated memory
		std::cout << FADE "delete Character 'bob' (left in slot: cure, ice, none, none)" NONE << std::endl;
		delete bob;
		std::cout << FADE "delete Character 'me' (left in slot: none, ice, none, none)" NONE << std::endl;
		delete me;
		std::cout << FADE "delete MateriaSource 'src' (with ice and cure learned)" NONE << std::endl;
		delete src;
		std::cout << FADE "delete materias left on the floor (cure)" NONE << std::endl;
		for (int i = 0; i < 1024; i++) {
			if (Character::floor[i]) {
				delete Character::floor[i];
				Character::floor[i] = NULL;
			}
		}
	}
	{
		// extra test 2 - copy assignment operators
		std::cout << std::endl << GREEN "Extra test 2 - copy assignment operators" NONE << std::endl;

		std::cout << std::endl;	
		// create a Materia Source, and learn Materia 'Ice' and Materia 'Cure'
		std::cout << FADE "create MateriaSource 'src1'" NONE << std::endl;
		IMateriaSource* src1 = new MateriaSource();
		std::cout << FADE "MateriaSource 'src1' learn Materia 'ice'" NONE << std::endl;
		src1->learnMateria(new Ice());
		std::cout << FADE "MateriaSource 'src1' learn Materia 'cure'" NONE << std::endl;
		src1->learnMateria(new Cure());

		std::cout << std::endl;	
		// create another Materia Source, and learn Materia 'Cure', 'Cure', 'Cure'
		std::cout << FADE "create MateriaSource 'src2'" NONE << std::endl;
		IMateriaSource* src2 = new MateriaSource();
		std::cout << FADE "MateriaSource 'src2' learn Materia 'cure'" NONE << std::endl;
		src2->learnMateria(new Cure());
		std::cout << FADE "MateriaSource 'src2' learn Materia 'cure'" NONE << std::endl;
		src2->learnMateria(new Cure());
		std::cout << FADE "MateriaSource 'src2' learn Materia 'cure'" NONE << std::endl;
		src2->learnMateria(new Cure());

		std::cout << std::endl;	
		// test copy assignment operator of MateriaSource class
		std::cout << FADE "make MateriaSource 'src2' = 'src1'" NONE << std::endl;
		std::cout << FADE "On src2[0]: delete cure -> copy ice from src1[0]" NONE << std::endl;
		std::cout << FADE "On src2[1]: delete cure -> copy cure from src1[1]" NONE << std::endl;
		std::cout << FADE "On src2[2]: delete cure" NONE << std::endl;
		*(MateriaSource*)src2 = *(MateriaSource*)src1;

		std::cout << std::endl;
		// create Character 'me' and equip it
		std::cout << FADE "create Character 'me'" NONE << std::endl;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << FADE "equip 'me' with a new 'cure' on slot[0]" NONE << std::endl;
		tmp = src2->createMateria("cure");
		me->equip(tmp);
		std::cout << FADE "equip 'me' with a new 'ice' on slot[1]" NONE << std::endl;
		tmp = src2->createMateria("ice");
		me->equip(tmp);
		std::cout << FADE "equip 'me' with a new 'cure' on slot[2]" NONE << std::endl;
		tmp = src2->createMateria("cure");
		me->equip(tmp);
		std::cout << FADE "equip 'me' with a new 'ice' on slot[3]" NONE << std::endl;
		tmp = src2->createMateria("ice");
		me->equip(tmp);
		std::cout << FADE "equip 'me' with a new 'cure' on slot[4] (should not secceed)" NONE << std::endl;
		tmp = src2->createMateria("cure");
		me->equip(tmp);

		std::cout << std::endl;
		// create Character 'bob' and equip it
		std::cout << FADE "create Character 'bob'" NONE << std::endl;
		ICharacter* bob = new Character("bob");
		std::cout << FADE "equip 'bob' with a new 'ice' on slot[0]" NONE << std::endl;
		tmp = src1->createMateria("ice");
		bob->equip(tmp);
		std::cout << FADE "equip 'bob' with the same 'ice' on slot[1] (should not secceed)" NONE << std::endl;
		bob->equip(tmp);
		std::cout << FADE "equip 'bob' with a new 'ice' on slot[1]" NONE << std::endl;
		tmp = src1->createMateria("ice");
		bob->equip(tmp);
		std::cout << FADE "equip 'bob' with a new 'ice' on slot[2]" NONE << std::endl;
		tmp = src1->createMateria("ice");
		bob->equip(tmp);

		std::cout << std::endl;
		// test copy assignment operator of Character class
		std::cout << FADE "make Character 'bob' (slot: ice, ice, ice, none) = Character 'me' (slot: cure, ice, cure, ice)" NONE << std::endl;
		std::cout << FADE "On bob's slot[0]: delete ice -> copy cure from me's slot[0]" NONE << std::endl;
		std::cout << FADE "On bob's slot[1]: delete ice -> copy ice from me's slot[1]" NONE << std::endl;
		std::cout << FADE "On bob's slot[2]: delete ice -> copy cure from me's slot[2]" NONE << std::endl;
		std::cout << FADE "On bob's slot[3]: copy ice from me's slot[4]" NONE << std::endl;
		*(Character*)bob = *(Character*)me;

		std::cout << std::endl;
		// test the usage of equipment
		std::cout << FADE "Character 'me' use slot[1] (ice) on Character 'bob' (renamed as 'me' by copy assignment)" NONE << std::endl;
		me->use(1, *bob);
		std::cout << FADE "Character 'me' use slot[0] (cure) on Character 'bob' (renamed as 'me' by copy assignment)" NONE << std::endl;
		me->use(0, *bob);
		std::cout << FADE "Character 'bob' (renamed as 'me' by copy assignment) use slot[3] (ice) on Character 'me'" NONE << std::endl;
		bob->use(3, *me);

		std::cout << std::endl;	
		// delete allocated memory
		std::cout << FADE "delete Character 'bob' (left in slot: cure, ice, cure, none)" NONE << std::endl;
		delete bob;
		std::cout << FADE "delete Character 'me' (left in slot: none, none, cure, ice)" NONE << std::endl;
		delete me;
		std::cout << FADE "delete MateriaSource 'src1' (with ice and cure learned)" NONE << std::endl;
		delete src1;
		std::cout << FADE "delete MateriaSource 'src2' (with ice and cure learned)" NONE << std::endl;
		delete src2;
		std::cout << FADE "delete materias left on the floor (cure)" NONE << std::endl;
		for (int i = 0; i < 1024; i++) {
			if (Character::floor[i]) {
				delete Character::floor[i];
				Character::floor[i] = NULL;
			}
		}
	}
	std::cout << std::endl << GREEN "All tests done" NONE << std::endl << std::endl;
	return 0;
}
