/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:10:52 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/18 20:03:49 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#define GREEN "\033[1;32m"
#define FADE "\033[2m"

int main()
{
	{
		std::cout << std::endl << GREEN "Test an array of animals" NONE << std::endl;

		int				count = 10;
		const Animal*	arr[count];
		
		std::cout << std::endl << FADE "Construction:" NONE << std::endl;
		for (int i = 0; i < count; i++) {
			if (i % 2 == 0)
				arr[i] = new Dog();
			else
				arr[i] = new Cat();
		}

		std::cout << std::endl << FADE "getType(): " NONE << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << arr[i]->getType() << std::endl;

		std::cout << std::endl << FADE "makeSound(): " NONE << std::endl;
		for (int i = 0; i < 10; i++)
			arr[i]->makeSound();

		std::cout << std::endl << FADE "thinkAloud(): " NONE << std::endl;
		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0)
				((const Dog*)arr[i])->thinkAloud();
			else
				((const Cat*)arr[i])->thinkAloud();
		}

		std::cout << std::endl << FADE "Destruction:" NONE << std::endl;
		for (int i = 0; i < 10; i++)
			delete arr[i];
	}
	{
		std::cout << std::endl << GREEN "Test for copy constructor" NONE << std::endl;

		std::cout << FADE "Construct animal a (dog) with default constructor:" NONE << std::endl;
		const Animal*	a = new Dog();
		std::cout << FADE "Construct animal b (dog) with copy constructor:" NONE << std::endl;
		const Animal*	b = new Dog((const Dog&)*a);

		std::cout << FADE "Animal a getType(): " NONE;
		std::cout << a->getType() << std::endl;
		std::cout << FADE "Animal b getType(): " NONE;
		std::cout << b->getType() << std::endl;

		std::cout << FADE "Animal a makeSound(): " NONE;
		a->makeSound();
		std::cout << FADE "Animal a makeSound(): " NONE;
		b->makeSound();
	
		std::cout << FADE "Animal a thinkAloud(): " NONE;
		((const Dog*)a)->thinkAloud();
		std::cout << FADE "Animal b thinkAloud(): " NONE;
		((const Dog*)b)->thinkAloud();

		std::cout << FADE "Destruct animal a (dog):" NONE << std::endl;
		delete a;
		std::cout << FADE "Destruct animal b (dog):" NONE << std::endl;
		delete b;
	}
	std::cout << std::endl;
	return 0;
}
