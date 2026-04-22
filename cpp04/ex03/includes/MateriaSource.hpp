/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:44:30 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 13:38:37 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *learn[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator=(MateriaSource &other);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type) ;
        ~MateriaSource();
};

#endif