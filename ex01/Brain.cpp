/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:26:07 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/22 23:13:52 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	this->ideas = new std::string[100];
	std::string	temp[100] = {
        "I wonder if there's a treat hidden somewhere.",
        "I could chase my tail for hours!",
        "Napping in the sun is the best.",
        "I should dig a new hole in the yard.",
        "What's that noise? Better go investigate.",
        "Maybe today I'll catch that squirrel.",
        "Is it dinner time yet?",
        "I bet I can jump higher than ever today!",
        "Time for a belly rub, please.",
        "Where did I bury that bone again?",
        "This shoe looks like a good chew toy.",
        "I love how the wind feels in my fur.",
        "A butterfly! Must chase it!",
        "I need to guard the house while my humans are away.",
        "That ball is mine, all mine!",
        "I think I deserve a treat for being so cute.",
        "Time to practice my pounce.",
        "Is that the mailman? Must bark loudly!",
        "I should check every corner of the house.",
        "Cuddling with my human is the best.",
        "I wonder what the cat is thinking.",
        "Rolling in the grass feels so good.",
        "I think I smell a friend nearby.",
        "What if I just nap a little longer?",
        "I hear a bag crinkling, could be food!",
        "Let's see how fast I can run!",
        "Who needs a reason to wag their tail?",
        "I love it when my human scratches behind my ears.",
        "Is it time for a walk yet?",
        "I should give everyone a big, wet kiss.",
        "Chasing my shadow is so fun!",
        "I need to rearrange my toys.",
        "I hear footsteps, must greet everyone!",
        "I think I need a new stick to chew on.",
        "Bouncing around makes me happy.",
        "I should dig a bit more in the garden.",
        "I love car rides with the windows down.",
        "What's that smell? Smells interesting.",
        "I hope someone plays fetch with me today.",
        "I need to be extra good for more treats.",
        "Let's see if I can catch my tail this time.",
        "I feel like today is a good day for exploring.",
        "I love belly rubs!",
        "Maybe I should bark just to see what happens.",
        "Time to patrol the yard.",
        "I hear something! Must investigate!",
        "I think I need to stretch my legs.",
        "A new toy would be nice.",
        "Sniffing everything is my job.",
        "I'm the best watchdog ever.",
        "Let's find something new to play with.",
        "I hope I see my dog friends today.",
        "Time for a quick nap.",
        "I love how my fur shines in the sun.",
        "I think I see a bird! Must chase it!",
        "I wonder if I can climb that.",
        "I need to keep practicing my tricks.",
        "Maybe today I'll find a new stick.",
        "I love it when my human talks to me.",
        "Is it snack time yet?",
        "I think I should be the center of attention.",
        "I need to protect my family.",
        "I should explore the backyard again.",
        "I wonder if the neighbor dog is out.",
        "I think I can dig the deepest hole ever.",
        "I should try to catch that butterfly again.",
        "I love the feeling of grass under my paws.",
        "Maybe I'll roll over for a treat.",
        "I wonder if I can jump over that fence.",
        "I hope someone throws a ball for me.",
        "I love playing tug-of-war.",
        "I should practice my howling.",
        "What's that? I must find out!",
        "I need to mark my territory.",
        "I love when my human gives me a bath.",
        "I think I should bark at the vacuum.",
        "I love when we go to the park.",
        "I need to sniff every inch of this place.",
        "I should bring my human a gift.",
        "I think I deserve another treat.",
        "I need to find the comfiest spot to sleep.",
        "I love the sound of birds chirping.",
        "Maybe I'll catch a frisbee today.",
        "I should dig up that old bone.",
        "I hope someone scratches my back.",
        "I love running through the sprinklers.",
        "I need to find out what's in that bush.",
        "I should practice my fetching skills.",
        "I think I'll cuddle with my human.",
        "I hope I get a new toy soon.",
        "I love the feeling of dirt between my paws.",
        "Maybe I'll meet a new friend today.",
        "I should practice my puppy eyes.",
        "I love when my human calls me a good boy/girl.",
        "I need to bark at that passing car.",
        "I hope I get some table scraps.",
        "I should chew on something.",
        "I love when the whole family is together."
    };
	for (int i = 0; i < 100; i++)
		this->ideas[i] = temp[i];
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain&	Brain::operator=(const Brain& src) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this->ideas) {
		delete[] this->ideas;
		this->ideas = new std::string[100];
	}
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return *this;
}
 
Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
	delete[] this->ideas;
}

std::string&	Brain::randomIdea() {
    std::srand(std::time(0));
    int	i = std::rand() % 100;
    return this->ideas[i];
}
