/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:44:30 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/10 15:49:05 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
    public:
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type) ;
        ~MateriaSource();

};

#endif