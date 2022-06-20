#ifndef SIN_F_H
#define SIN_F_H
#include "blocks/gain/gain.h"
#include "integral.h"
#include "unit_delay.h"
class Sin_f
{
public:
    Sin_f();
    float getSin_fValue() const;
    float update(float dt);
private:
    float unit_delay_1;
    float unit_delay_2;
    gain *gain_0;
    gain *gain_1;
    gain *gain_2;
    gain *gain_3;
    gain *gain_4;

    Unit_delay *unit_delay_sin_1;
    Unit_delay *unit_delay_sin_2;
};

#endif // SIN_F_H
