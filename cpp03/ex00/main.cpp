/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:31:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/01 10:44:26 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    clap_lili("lili");
    ClapTrap    clap_2(clap_lili);
    ClapTrap    clap_toto("toto");
    ClapTrap    clap_test;
    

    clap_test = clap_toto;
    clap_test.setName("roro");
    clap_test.setAttackDamage(1);
    clap_test.attack("toto");
    clap_toto.takeDamage(clap_test.getAttackDamage());
    clap_toto.setAttackDamage(9);
    clap_toto.attack("lili");
    clap_lili.takeDamage(clap_toto.getAttackDamage());
    clap_lili.beRepaired(1);
    clap_toto.attack("lili");
    clap_lili.takeDamage(clap_toto.getAttackDamage());

    clap_2.setAttackDamage(2);
    clap_2.attack("toto");
    clap_toto.takeDamage(clap_2.getAttackDamage());
    clap_lili.attack("toto");
    
    return 0;
}
