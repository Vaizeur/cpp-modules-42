/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:29:28 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/24 11:40:03 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm form("vaiz");
	Bureaucrat bc(149,"bc");
	bc.signForm(form);
	bc.executeForm(form);
}
