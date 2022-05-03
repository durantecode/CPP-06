/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:01:08 by ldurante          #+#    #+#             */
/*   Updated: 2022/05/04 01:08:56 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

void convert(const char *input)
{
	Conversion myConversion(input);

	myConversion.printChar();
	myConversion.printInt();
	myConversion.printFloat();
	myConversion.printDouble();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	else
		convert(argv[1]);
	return (0);
}