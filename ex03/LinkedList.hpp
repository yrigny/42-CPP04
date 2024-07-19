/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:21:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/19 20:36:12 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_HPP
# define LINKED_LIST_HPP

struct		s_node {
	
	void*	content;
	s_node*	next;
};


class	LinkedList {

	private:

		s_node*	head;

	public:

		LinkedList();
		// LinkedList(const LinkedList& src);
		~LinkedList();
		// LinkedList&	operator=(const LinkedList& src);

		void	insert(void *node);
};

#endif
