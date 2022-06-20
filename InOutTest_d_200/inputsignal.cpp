#include "inputsignal.h"
#include "exp.h"
#include "sin_f.h"
InputSignal::InputSignal()
{
    exp = new Exp();
    sin_f = new Sin_f();
    input_value = exp->getExpValue()+sin_f->getSin_fValue();
}
float InputSignal::getInputValue() const{
    return  input_value;
}

float InputSignal::update(float dt){

    input_value = exp->update(dt)+sin_f->update(dt);
    return input_value;
}
