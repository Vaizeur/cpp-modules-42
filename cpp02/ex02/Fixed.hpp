/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:20:36 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/21 10:23:11 by odanyliu         ###   ########.fr       */
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
				
		bool 	operator==(const Fixed& other) const;
		bool 	operator<(const Fixed& other) const;
		bool 	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		Fixed	operator++();
   		Fixed	operator++(int);
		Fixed	operator--();
   		Fixed	operator--(int);

		static Fixed& max(Fixed &a, Fixed &b);
		static Fixed& min(Fixed &a, Fixed &b);

		static const Fixed& max(const Fixed &a, const Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif

