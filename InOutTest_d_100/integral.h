#ifndef INTEGRAL_H
#define INTEGRAL_H


class Integral
{
public:
    Integral(float init_state);
    float getIntegralValue() const;
    float update(float input, float dt);
private:
    float state;
    float prev_in;
};

#endif // INTEGRAL_H
