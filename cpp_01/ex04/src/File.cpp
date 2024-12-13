#include "File.hpp"

File::File(std::string file) : _fileNameIn(file), _fileNameOut(file + ".replace"), _occurenceUpdated(0)
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
	std::string	occ;
	
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
		if (_in.good() && _out.good())
			_out << line << std::endl;
		else if (_in.eof() && _out.good())
			_out << line;
	}
	_printStatus(s1, s2);
	_in.close();
	_out.close();
}

int File::_openAndCheckFileIn(void)
{
	_in.open(_fileNameIn.c_str());
	if (!_in.is_open() && _in.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error opening file: " << _fileNameIn << " - " << std::flush;
		std::perror("");
		return -1;
	}
	return 0;
}

int File::_openAndCheckFileOut(void)
{
	_out.open(_fileNameOut.c_str());
	if (!_out.is_open())
	{
		std::cerr << "Error opening file: " << _fileNameIn << " - " << std::flush;
		std::perror("");
		return -1;
	}
	return 0;
}

void File::_replaceWord(std::string &s1, std::string &s2, std::string &line)
{
	size_t pos = 0, sizeS1 = s1.size();

	if (s1.empty()) return ;
	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, sizeS1).insert(pos, s2);
		_occurenceUpdated++;
		pos = line.find(s1, pos + 1);
	}
}

void File::_printStatus(std::string s1, std::string s2)
{
	if (_occurenceUpdated == 0)
		std::cout << "No occurence of " << s1 << " was found in " << _fileNameIn << std::endl;
	else if (_occurenceUpdated == 1)
		std::cout << _occurenceUpdated << " occurence of " << s1 << " was found and replaced by " << s2 << " in " << _fileNameIn << std::endl;
	else
		std::cout << _occurenceUpdated << " occurences of " << s1 << " was found and replaced by " << s2 << " in " << _fileNameIn << std::endl;
}
