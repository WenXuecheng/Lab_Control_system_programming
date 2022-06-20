#include "integral.h"

Integral::Integral(float init_state)
{
    state = init_state;
}
float Integral::getIntegralValue() const
{
    return this->state;
}
float Integral::update(float input, float dt){
    state = state + (prev_in+input)*dt/2;
    prev_in = input;
    return state;
}
