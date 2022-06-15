/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:41:19 by ldurante          #+#    #+#             */
/*   Updated: 2022/06/15 14:03:13 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* reinterpret_cast<type> (expr) − 
reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes.
The operation result is a simple binary copy of the value from one pointer to the other.
All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

It can also cast pointers to or from integer types. The format in which this integer value
represents a pointer is platform-specific. The only guarantee is that a pointer cast to an
integer type large enough to fully contain it, is granted to be able to be cast back to a valid pointer. */

struct Data
{
	std::string s;
	int			x;
};

uintptr_t serialize(Data *ptr)
{
	uintptr_t casted;

	casted = reinterpret_cast<uintptr_t>(ptr);
	return (casted);
}

Data *deserialize(uintptr_t raw)
{
	Data *casted;

	casted = reinterpret_cast<Data*>(raw);
	return (casted);
}

int main(void)
{
	Data data;
	Data *recastedData;
	uintptr_t raw;

	data.s = "Some serious data here!";
	data.x = 50;
	std::cout << "BEFORE SERIALIZE:\n" << std::endl;
	std::cout << "Memory address: " << &data << "\nString: " << data.s << "\nInt: " << data.x << std::endl;

	raw = serialize(&data);
	recastedData = deserialize(raw);

	std::cout << "\n-------------------\n";
	std::cout << "AFTER SERIALIZE:\n" << std::endl;
	std::cout << "Memory address: " << recastedData << "\nString: " << recastedData->s << "\nInt: " << recastedData->x << std::endl;
	
	return (0);
}
