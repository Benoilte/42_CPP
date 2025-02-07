#include "utils.hpp"

int	main(void)
{
	// Serializer ser;
	Data		d;
	Data		*ptr1 = &d;
	Data		*ptr2;
	uintptr_t	raw;

	std::cout << YELLOW << "Test Serialization of data structure\n" << RESET << std::endl;

	// Test Serialization on ptr1 without memory allocation

	std::cout << CYAN << "Serialize data structure of ptr1" << RESET << std::endl;
	ptr1->myNum = 42;
	ptr1->myString = "Beniben";
	std::cout << "myNum: " << ptr1->myNum << " myString: " << ptr1->myString << std::endl;
	raw = Serializer::serialize(ptr1);
	ptr1 = Serializer::deserialize(raw);
	std::cout << "myNum: " << ptr1->myNum << " myString: " << ptr1->myString << std::endl;

	// Test Serialization on ptr2 with memory allocation

	std::cout << CYAN << "\nSerialize data structure of ptr2" << RESET << std::endl;
	ptr2 = new Data;
	ptr2->myNum = 84;
	ptr2->myString = "Johny be good";
	std::cout << "myNum: " << ptr2->myNum << " myString: " << ptr2->myString << std::endl;
	raw = Serializer::serialize(ptr2);
	ptr2 = Serializer::deserialize(raw);
	std::cout << "myNum: " << ptr2->myNum << " myString: " << ptr2->myString << std::endl;
	delete ptr2;

	return (0);
}

