#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &t_src) : WrongAnimal(t_src)
{
	std::cout << "WrongCat copy constructor is called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &m_rhs)
{
	if (this != &m_rhs)
		WrongAnimal::operator=(m_rhs);
	return *this;

}

void WrongCat::makeSound() const
{
	std::cout << "Miaouw" << std::endl;
}
