#ifndef INPUTSIGNAL_H
#define INPUTSIGNAL_H
#include "exp.h"
#include "sin_f.h"

class InputSignal
{
public:
    InputSignal();
    float getInputValue() const;
    float update(float dt);
private:
    float input_value;
    Exp *exp;
    Sin_f *sin_f;
};


#endif // INPUTSIGNAL_H
