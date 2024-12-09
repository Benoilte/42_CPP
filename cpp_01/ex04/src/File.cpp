#include "File.hpp"

File::File(std::string file) : _fileNameIn(file), _fileNameOut(file + ".replace")
{
	/*Constructor*/
}

File::~File()
{
	/*Destructor*/
}

void File::sed(std::string s1, std::string s2)
{
	std::string line;

	(void)s1;
	(void)s2;
	if (_openAndCheckFileIn() != 0)
		return ;
	if (_openAndCheckFileOut() != 0)
	{
		_in.close();
		return ;
	}
	while(_in.good())
	{
		getline(_in, line);
		_replaceWord(s1, s2, line);
		if (_out.good())
			_out << line << std::endl;
	}
	_in.close();
	_out.close();
}

int File::_openAndCheckFileIn(void)
{
	_in.open(_fileNameIn.c_str());
	if (!_in.is_open())
	{
		std::cout << "Error opening file: " << _fileNameIn << std::endl;
		return -1;
	}
	return 0;
}

int File::_openAndCheckFileOut(void)
{
	_out.open(_fileNameOut.c_str());
	if (!_out.is_open())
	{
		std::cout << "Error opening file: " << _fileNameOut << std::endl;
		return -1;
	}
	return 0;
}

void File::_replaceWord(std::string &s1, std::string &s2, std::string &line)
{
	size_t pos = 0, sizeS1 = s1.size();

	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, sizeS1).insert(pos, s2);
		pos = line.find(s1);
	}
}
