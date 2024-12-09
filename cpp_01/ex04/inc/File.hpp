#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class File
{
	public:

		File(std::string file);
		~File();

		void	sed(std::string s1, std::string s2);

	private:

		std::string		_fileNameIn;
		std::string		_fileNameOut;
		std::ifstream	_in;
		std::ofstream	_out;

		int	_openAndCheckFileIn(void);
		int	_openAndCheckFileOut(void);
		void	_replaceWord(std::string &s1, std::string &s2, std::string &line);
};



#endif
