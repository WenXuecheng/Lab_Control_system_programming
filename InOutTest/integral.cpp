#include "integral.h"

Integral::Integral(float init_state, float init_input)
{
    state = init_state;
    pre_state = 0;
    prev_in = init_input;


}
float Integral::getStateValue() const
{
    return this->state;
}
float Integral::getPrestateValue() const{
    return this->pre_state;
}
void Integral::InitValue() {
    pre_state = 0;
    state = 0;
}
float Integral::update(float input, float dt){
    pre_state = state;
    state = state + (prev_in+input)*dt/2;
    prev_in = input;
    return state;
}
