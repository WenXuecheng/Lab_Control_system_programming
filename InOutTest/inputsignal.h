#ifndef INPUTSIGNAL_H
#define INPUTSIGNAL_H
#include "exp.h"
#include "sin_f.h"

class InputSignal
{
public:
    InputSignal();
    float getInputValue() const;
    float getPre_inputValue() const;
    float getPPre_inputValue() const;
    float update(float dt);
private:
    float input_value;
    float pre_input_value;
    float ppre_input_value;
    Exp *exp;
    Sin_f *sin_f;
};


#endif // INPUTSIGNAL_H
