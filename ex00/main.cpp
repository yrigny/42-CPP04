/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:10:52 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 16:10:26 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#define GREEN "\033[1;32m"
#define FADE "\033[2m"
#define NONE "\033[0m"

int main()
{
	{
		std::cout << std::endl << GREEN "Test provided in the subject" NONE << std::endl;

		std::cout << FADE "Construct animal meta (default animal):" NONE << std::endl;
		const Animal*	meta = new Animal();
		std::cout << FADE "Construct animal j (dog):" NONE << std::endl;
		const Animal*	j = new Dog();
		std::cout << FADE "Construct animal i (cat):" NONE << std::endl;
		const Animal*	i = new Cat();

		std::cout << FADE "Get Animal j's type: " NONE;
		std::cout << j->getType() << " " << std::endl;
		std::cout << FADE "Get Animal i's type: " NONE;
		std::cout << i->getType() << " " << std::endl;

		std::cout << FADE "Make Animal i's sound: " NONE;
		i->makeSound(); //will output the cat sound!
		std::cout << FADE "Make Animal j's sound: " NONE;
		j->makeSound(); //will output the dog sound!
		std::cout << FADE "Make Animal meta's sound: " NONE;
		meta->makeSound(); //will output the default animal sound!
		
		std::cout << FADE "Destruct animal meta (default animal):" NONE << std::endl;
		delete meta;
		std::cout << FADE "Destruct animal j (dog):" NONE << std::endl;
		delete j;
		std::cout << FADE "Destruct animal i (cat):" NONE << std::endl;
		delete i;
	}
	{
		std::cout << std::endl << GREEN "Test for wrong implementation" NONE << std::endl;

		std::cout << FADE "Construct animal meta (default animal):" NONE << std::endl;
		const WrongAnimal*	meta = new WrongAnimal();
		std::cout << FADE "Construct animal i (cat):" NONE << std::endl;
		const WrongAnimal*	i = new WrongCat();

		std::cout << FADE "Make Animal i's sound: " NONE;
		i->makeSound(); //will output the default animal sound!
		std::cout << FADE "Make Animal meta's sound: " NONE;
		meta->makeSound(); //will output the default animal sound!

		std::cout << FADE "Destruct animal meta (default animal):" NONE << std::endl;
		delete meta;
		std::cout << FADE "Destruct animal i (cat):" NONE << std::endl;
		delete i;
	}
	{
		std::cout << std::endl << GREEN "Extra tests - copy constructor" NONE << std::endl;

		std::cout << FADE "Construct animal a (dog) with default constructor:" NONE << std::endl;
		const Animal*	a = new Dog();
		std::cout << FADE "Construct animal b (dog) with copy constructor:" NONE << std::endl;
		const Animal*	b = new Dog((const Dog&)*a);

		std::cout << FADE "Get Animal a's type: " NONE;
		std::cout << a->getType() << " " << std::endl;
		std::cout << FADE "Get Animal b's type: " NONE;
		std::cout << b->getType() << " " << std::endl;

		std::cout << FADE "Make Animal a's sound: " NONE;
		a->makeSound();
		std::cout << FADE "Make Animal b's sound: " NONE;
		b->makeSound();

		std::cout << FADE "Destruct animal a (dog):" NONE << std::endl;
		delete a;
		std::cout << FADE "Destruct animal b (dog):" NONE << std::endl;
		delete b;
	}
	std::cout << std::endl;
	return 0;
}
