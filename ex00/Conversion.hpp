/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 00:46:04 by ldurante          #+#    #+#             */
/*   Updated: 2022/05/04 01:03:49 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#define	MIN_DISPLAY 33
#define MAX_DISPLAY 126
#include <iostream>
#include <limits>
#include <iomanip>

class Conversion
{
	private:
		double m_converted;
		Conversion(void);

	public:
		Conversion(const char *input);
		Conversion(Conversion const &toCopy);
		~Conversion(void);
		Conversion &operator = (Conversion const &toCopy);

		void printChar(void);
		void printInt(void);
		void printFloat(void);
		void printDouble(void);
};

#endif
