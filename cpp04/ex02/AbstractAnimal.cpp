#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal() : type("AbstractAnimal") {}

AbstractAnimal::AbstractAnimal(std::string type) : type(type) {}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &copy) : type(copy.type) {}

AbstractAnimal::~AbstractAnimal() {}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this);
}

std::string AbstractAnimal::getType() const
{
	return (type);
}
