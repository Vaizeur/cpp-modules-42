/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:37:06 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 14:21:45 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *horde = zombieHorde(10, "lili");

    for (size_t i = 0; i < 10; i++)
        horde[i].announce();       
    delete [] horde;
    return 0;
}
