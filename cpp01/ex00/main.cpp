/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:37:06 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 14:05:08 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *z1 = newZombie("Toto");
    z1->announce();
    delete z1;

    std::cout << "-------------------" << std::endl;
    randomChump("Lili");
    std::cout << "-------------------" << std::endl;

    return 0;
}
