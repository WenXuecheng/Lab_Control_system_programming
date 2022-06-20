#ifndef INTEGRAL_H
#define INTEGRAL_H


class Integral
{
public:
    Integral(float init_state, float init_input);
    float getStateValue() const;
    float getPrestateValue() const;
    float update(float input, float dt);
private:
    float state;
    float pre_state;
    float prev_in;
};

#endif // INTEGRAL_H
