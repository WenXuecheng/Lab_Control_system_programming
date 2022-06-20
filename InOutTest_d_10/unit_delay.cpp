#include "unit_delay.h"

Unit_delay::Unit_delay(float init_state)
{
    pre_state = 0;
    state = init_state;

}
float Unit_delay::getUnit_delayValue() const{
    return state;
}
float Unit_delay::getUnit_delayPreValue() const{
    return pre_state;
}
float Unit_delay::update(float input){
    pre_state = state;
    state = input;
    return state;
}

