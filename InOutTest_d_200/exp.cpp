#include "exp.h"

Exp::Exp()
{
    gain_exp = new gain(0.8187);
    exp_value = 3;
    unit_delay_exp = new Unit_delay(3);

}
float Exp::getExpValue() const{
    return  exp_value;
}

float Exp::update(float dt){

    exp_value = unit_delay_exp->update(gain_exp->update(exp_value));
    return exp_value;
}
