#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
#include "colors.hpp"

class Brain
{
	public:

		Brain();
		Brain(const Brain &t_src);
		~Brain();

		Brain	&operator=(const Brain &t_rhs);

		const std::string	getIdeas(unsigned int t_pos) const;
		void				setIdeas(unsigned int t_pos, std::string t_idea);

	private:
		std::string	m_ideas[100];
	
};

#endif
