#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


class Factory
{
public:
	static Base *generate(void);
	static void identify(Base *p);
	static void identify(Base &p);
};