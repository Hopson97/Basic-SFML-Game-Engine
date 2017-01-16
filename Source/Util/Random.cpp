#include "Random.h"

#include <cstdlib>
#include <ctime>
#include <cmath>

namespace Random
{

    void init()
    {
        srand(time(nullptr));
    }

	int integer(int low, int high)
	{
		return rand() % (high - low + 1) + low;
	}

	double decimal(double low, double high, int precision)
	{
		auto multiplier = pow(10, precision);

		low *= multiplier;
		high *= multiplier;

		auto newNum = integer(low, high);

		return newNum / multiplier;
	}
}
