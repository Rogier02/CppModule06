#include "Serializer.hpp"

int main()
{
	Data* originalPtr = new Data();
	originalPtr->name = "Rogier";
	originalPtr->vocation = "Student";
	originalPtr->age = 42;
	originalPtr->vegan = false;

	std::cout << "Original pointer:     " << originalPtr << std::endl;

	uintptr_t raw = Serializer::serialize(originalPtr);
	Data* deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
	std::cout << "Pointers match:       " << (originalPtr == deserializedPtr ? "yes" : "no") << std::endl;

	std::cout << "name: " << deserializedPtr->name << std::endl;
	std::cout << "vocation: " << deserializedPtr->vocation << std::endl;
	std::cout << "age: " << deserializedPtr->age << std::endl;
	std::cout << "vegan: " << deserializedPtr->vegan << std::endl;

	delete originalPtr;

	return 0;
}
