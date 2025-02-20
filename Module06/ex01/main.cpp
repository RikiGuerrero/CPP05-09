#include "Serializer.hpp"

int main()
{
	data_t data;
	data.text = "Hello, Serialization!";

	uintptr_t raw = Serializer::serialize(&data);

	data_t *ptr = Serializer::deserialize(raw);

	std::cout << "Original address: " << &data << std::endl;
	std::cout << "Deserialized address: " << ptr << std::endl;

	std::cout << "Deserialized text: " << ptr->text << std::endl;

	return (0);
}