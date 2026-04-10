/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:59:45 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/07 13:06:52 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain &other);
		Brain& operator=(Brain &other);
		~Brain();
};

#endif