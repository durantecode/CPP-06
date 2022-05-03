/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 00:52:24 by ldurante          #+#    #+#             */
/*   Updated: 2022/05/04 01:05:03 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void)
{

}

Conversion::Conversion(const char *input)
{
	this->m_converted = atof(input);
}

Conversion::Conversion(Conversion const &toCopy)
{
	*this = toCopy;
}

Conversion &Conversion::operator = (Conversion const &toCopy)
{
	this->m_converted = toCopy.m_converted;
	return *this;
}

void Conversion::printChar(void)
{
	if (!(this->m_converted >= CHAR_MIN && this->m_converted <= CHAR_MAX))
		std::cout << "char: impossible" << std::endl;
	else if (!(this->m_converted >= MIN_DISPLAY && this->m_converted <= MAX_DISPLAY))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(this->m_converted) << "'" << std::endl;
}

void Conversion::printInt(void)
{
	if (this->m_converted <= INT_MAX && this->m_converted >= INT_MIN)
		std::cout << "int: " << static_cast<int>(this->m_converted) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void Conversion::printFloat(void)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(this->m_converted) << "f" << std::endl;
}

void Conversion::printDouble(void)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << this->m_converted << std::endl;
}

Conversion::~Conversion(void)
{

}
