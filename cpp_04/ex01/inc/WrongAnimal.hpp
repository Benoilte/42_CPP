#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &rhs);

		std::string		getType() const;
		void			makeSound() const;

	protected:

		WrongAnimal(const std::string &type);

		std::string	m_type;

	private:

};

#endif
