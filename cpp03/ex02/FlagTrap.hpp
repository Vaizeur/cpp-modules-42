/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:51:11 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/01 11:43:49 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_H
# define FLAGTRAP_H
# include "ScavTrap.hpp"


class FlagTrap : public ScavTrap
{
	public:
		FlagTrap(void);
		FlagTrap(std::string name);
		FlagTrap(FlagTrap &other);
        FlagTrap &operator=(const FlagTrap &other);
		~FlagTrap();
		void highFivesGuys(void);
};

#endif