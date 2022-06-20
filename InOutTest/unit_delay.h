#ifndef UNIT_DELAY_H
#define UNIT_DELAY_H


class Unit_delay
{
public:
    Unit_delay(float init_state,float input);
    float getUnit_delayValue() const;
    float update(float input);
private:
    float state;
    float prev;
};

#endif // UNIT_DELAY_H
