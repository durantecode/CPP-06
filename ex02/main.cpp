/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:15:21 by ldurante          #+#    #+#             */
/*   Updated: 2022/05/04 17:06:38 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base
{
	public:
		virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void)
{
	srand(time(NULL));
	int		random;
	Base	*generate;

	random = rand() % 3;
	switch(random)
	{
		case 0: generate = new A; break;
		case 1: generate = new B; break;
		case 2: generate = new C; break;
	}
	return (generate);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "Pointer is A class" << std::endl;
	if (b)
		std::cout << "Pointer is B class" << std::endl;
	if (c)
		std::cout << "Pointer is C class" << std::endl;
}

void identifyReference(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Reference is A class" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "Reference is B class" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "Reference is C class" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}

int main (void)
{
	Base *base;

	base = generate();
	identify(base);
	identifyReference(*base);

	delete base;
	return (0);
}