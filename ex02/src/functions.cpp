#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }

    switch (std::rand() % 3) {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;

}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast&) {
            std::cout << "C" << std::endl;
        }
    }
}
