#include "inputsignal.h"
#include "exp.h"
#include "sin_f.h"
InputSignal::InputSignal()
{
    exp = new Exp();
    sin_f = new Sin_f();
    input_value = exp->getExpValue()+sin_f->getSin_fValue();
    pre_input_value = 0;
    ppre_input_value = 0;
}
float InputSignal::getInputValue() const{
    return  input_value;
}
float InputSignal::getPre_inputValue() const{
    return  pre_input_value;
}
float InputSignal::getPPre_inputValue() const{
    return  ppre_input_value;
}
float InputSignal::update(float dt){
    ppre_input_value = pre_input_value;
    pre_input_value = input_value;
    input_value = exp->update(dt)+sin_f->update(dt);
    return input_value;
}
