#ifndef SIN_F_H
#define SIN_F_H
#include "blocks/gain/gain.h"
#include "integral.h"

class Sin_f
{
public:
    Sin_f();
    float getSin_fValue() const;
    float update(float dt);
private:
    float sin_f_value;
    float sin_f_x1;
    float sin_f_x2;
    gain *gain_sin;
    Integral *Integral_sin_1;
    Integral *Integral_sin_2;
};

#endif // SIN_F_H
