#include "functions.hpp"

int main()
{
	for (int i = 0; i < 5; i++)
	{
		Base* p = generate();

		identify(p);
		identify(*p);

		delete p;
	}

	return 0;
}
