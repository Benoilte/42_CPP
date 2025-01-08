#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor is called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return *this;

}

void WrongCat::makeSound() const
{
	std::cout << "Miaouw" << std::endl;
}
