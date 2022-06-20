#include "sin_f.h"
#include <math.h>
Sin_f::Sin_f()
{
    gain_sin = new gain(-0.25);

    Integral_sin_1 = new Integral(0.3536,0);
    Integral_sin_2 = new Integral(-0.1768,0);
    sin_f_value = Integral_sin_1->getStateValue();
    sin_f_x1 = sin_f_value;
    sin_f_x2 = Integral_sin_2->getStateValue();

}
float Sin_f::getSin_fValue() const{
    return  sin_f_value;
}

float Sin_f::update(float dt){
    sin_f_x2 = Integral_sin_2->update(gain_sin->update(Integral_sin_1->getStateValue()),dt);
    sin_f_x1 = Integral_sin_1->update(Integral_sin_2->getPrestateValue(),dt);
    sin_f_value = sin_f_x1;
    return sin_f_value;
}
