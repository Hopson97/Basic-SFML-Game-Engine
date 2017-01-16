#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

namespace Random
{
    void init();

    int integer (int low, int high);
    double decimal(double low, double high, int precision);
}

#endif // RANDOM_H_INCLUDED
