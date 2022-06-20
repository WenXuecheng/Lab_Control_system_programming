#ifndef EXP_H
#define EXP_H
#include "blocks/gain/gain.h"
#include "integral.h"

class Exp
{
public:
    Exp();
    float getExpValue() const;
    float update(float dt);
private:
    float exp_value;
    gain *gain_exp;
    Integral *Integral_exp;
};

#endif // EXP_H
