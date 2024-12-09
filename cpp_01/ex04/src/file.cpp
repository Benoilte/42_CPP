#include "file.hpp"

file::file(std::string file) : fileName(file)
{
    /*Constructor*/
}

file::~file()
{
    /*Destructor*/
}

void file::sed(std::string s1, std::string s2)
{
    std::string line;

    // create function to open and check in ifstream
    in.open(fileName.c_str());
	if (!in.is_open()) 
    {
        std::cout << "Error opening file";
        return ;
    }
    if (!in.good())
    {
        std::cout << "Your file cannot be read";
        return ;
    }
    // open and check out ofstream
    while(in.good())
    {
        getline(in, line);
        // replace s1 by s2 in line
        // add line into out ofstream
    }
}