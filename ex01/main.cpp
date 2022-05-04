/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:41:19 by ldurante          #+#    #+#             */
/*   Updated: 2022/05/04 14:13:47 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* reinterpret_cast<type> (expr) − 
The reinterpret_cast operator changes a pointer to any other type of pointer.
It also allows casting from pointer to an integer type and vice versa. */

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
	return casted;
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