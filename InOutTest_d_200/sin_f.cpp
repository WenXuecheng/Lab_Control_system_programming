#include "sin_f.h"
#include <math.h>
Sin_f::Sin_f()
{
    gain_0 = new gain(-0.0499);
    gain_1 = new gain(0.995);
    gain_2 = new gain(0.995);
    gain_3 = new gain(0.1997);



    unit_delay_1 = 0.3536;
    unit_delay_2 = -0.1768;
    unit_delay_sin_2 = new Unit_delay(-0.1768);
    unit_delay_sin_1 = new Unit_delay(unit_delay_1);


}
float Sin_f::getSin_fValue() const{
    return  unit_delay_1;
}

float Sin_f::update(float dt){
    unit_delay_2 = unit_delay_sin_2->update( gain_0->update(unit_delay_1) + gain_1->update(unit_delay_2));
    unit_delay_1 = unit_delay_sin_1->update( gain_2->update(unit_delay_1) + gain_3->update(unit_delay_sin_2->getUnit_delayPreValue()));
    return unit_delay_1;
}
