#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
    public:
        Base();
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);