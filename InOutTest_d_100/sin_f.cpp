#include "sin_f.h"
#include <math.h>
Sin_f::Sin_f()
{
    gain_0 = new gain(1);
    gain_1 = new gain(0.9988);
    gain_2 = new gain(0.1000);
    gain_3 = new gain(-0.0250);
    gain_4 = new gain(0.9988);


    unit_delay_1 = 0.3536;
    unit_delay_2 = -0.1768;
    unit_delay_sin_2 = new Unit_delay(-0.1768);
    unit_delay_sin_1 = new Unit_delay(unit_delay_1);


}
float Sin_f::getSin_fValue() const{
    return  unit_delay_1;
}

float Sin_f::update(float dt){
    unit_delay_2 = unit_delay_sin_2->update( gain_3->update(unit_delay_1) + gain_4->update(unit_delay_2));
    unit_delay_1 = unit_delay_sin_1->update( gain_1->update(unit_delay_1) + gain_2->update(unit_delay_sin_2->getUnit_delayPreValue()));
    return unit_delay_1;
}
