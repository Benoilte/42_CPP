#include <iostream>

int	main()
{
	std::string MyName;
	std::cin >> MyName;
	std::cout << "Hello " + MyName.substr(0, 3) << std::endl;
	return (0);
}
