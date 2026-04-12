#pragma once

#include <stdint.h>
#include <iostream>

struct Data
{
	int	id;
};

class Serialize
{
    public:
        ~Serialize();
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
    private:
            Serialize();
            Serialize(const Serialize& copy);
            Serialize&	operator=(const Serialize& copy);
};
