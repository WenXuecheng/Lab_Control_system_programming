#include "unit_delay.h"

Unit_delay::Unit_delay(float init_state,float input)
{
    state = init_state;
    prev = input;

}
float Unit_delay::getUnit_delayValue() const{
    return state;
}
float Unit_delay::update(float input){
    state = prev;
    prev = input;
    return state;
}

