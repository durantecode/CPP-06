/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:01:08 by ldurante          #+#    #+#             */
/*   Updated: 2022/06/15 13:53:59 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

/* static_cast<type> (expr):
static_cast can perform conversions between pointers to related classes, not only
from the derived class to its base, but also from a base class to its derived.
This ensures that at least the classes are compatible if the proper object is converted,
but no safety check is performed during runtime to check if the object being converted
is in fact a full object of the destination type. Therefore, it is up to the programmer
to ensure that the conversion is safe.

static_cast can also be used to perform any other non-pointer conversion that could
also be performed implicitly */

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
