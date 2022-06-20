#include "exp.h"

Exp::Exp()
{
    gain_exp = new gain(-1);
    Integral_exp = new Integral(3,0);
    exp_value = Integral_exp->getStateValue();

}
float Exp::getExpValue() const{
    return  exp_value;
}

float Exp::update(float dt){
    exp_value = Integral_exp->update( gain_exp->update(Integral_exp->getStateValue()),dt);
    return exp_value;
}
