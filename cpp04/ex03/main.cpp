#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"

void subjectTest()
{
	IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}
int main()
{
    std::cout << "Subject test" << std::endl;
	subjectTest();
	std::cout << "!!!!!!!!!!!!!!!!" << std::endl;

	std::cout << "My test" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* ice = src->createMateria("ice");
	me->equip(ice);
	AMateria* cure = src->createMateria("cure");
	me->equip(cure);
	AMateria* fire = src->createMateria("fire");
	me->equip(fire);
	AMateria* bobFire = src->createMateria("fire");
	bob->equip(bobFire);
	AMateria* garbage = src->createMateria("firwefwefe");
	me->equip(garbage); // will not do anything (no materia with type "firwefwefe")
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob); // will not do anything (no materia at index 3)
	me->use(4, *bob); // will not do anything (max materia count is 4)
	bob->use(0, *me);
	bob->use(1, *me); // will not do anything (no materia at index 1)
	bob->unequip(0);
	delete bobFire;
	me->unequip(1);
	delete cure;
	me->use(1, *bob); // will not do anything (no materia at index 1)
	delete bob;
	delete me;
	delete src;
    return 0;
}