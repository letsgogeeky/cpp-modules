#ifndef MATTERIASOURCE_HPP
#define MATTERIASOURCE_HPP

#include <iostream>

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *_materias[4];
        int _materiasCount;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &materiaSource);
        ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &materiaSource);
        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
};

#endif
