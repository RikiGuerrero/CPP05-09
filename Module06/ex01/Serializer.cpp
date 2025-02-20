#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(data_t *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

data_t *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<data_t *>(raw));
}