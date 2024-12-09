#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class file
{
	public:

		file(std::string file);
		~file();

		void	sed(std::string s1, std::string s2);

	private:
	
		std::string fileName;
		std::ifstream in;
		std::ofstream out;
		/* data */
};

#endif
