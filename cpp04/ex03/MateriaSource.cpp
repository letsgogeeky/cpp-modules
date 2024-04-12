#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiasCount(0)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
    *this = materiaSource;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    if (this == &materiaSource)
        return (*this);
    _materiasCount = materiaSource._materiasCount;
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
        _materias[i] = materiaSource._materias[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (_materiasCount < 4)
    {
        _materias[_materiasCount] = materia;
        _materiasCount++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
	std::cout << "WAKEUP!! No materia with type " << type << std::endl;
    return (NULL);
}
