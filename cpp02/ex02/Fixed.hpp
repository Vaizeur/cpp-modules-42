/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:20:36 by vaiz              #+#    #+#             */
/*   Updated: 2026/03/30 10:22:40 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int			_value;
		int			_fractionalB;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits(void) const;
		int		getFractionalB(void) const;

		friend std::ostream &operator<<(std::ostream &out, const Fixed &c);
		
		bool 	operator==(const Fixed& other);
		bool 	operator<(const Fixed& other);
		bool 	operator>(const Fixed& other);
		bool	operator<=(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator!=(const Fixed& other);

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		Fixed	operator++();
   		Fixed	operator++(int);
		Fixed	operator--();
   		Fixed	operator--(int);

		static Fixed max(Fixed a, Fixed b);
};


#endif

