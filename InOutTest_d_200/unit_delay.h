#ifndef UNIT_DELAY_H
#define UNIT_DELAY_H

#include <QDebug>

class Unit_delay
{
public:
    Unit_delay(float init_state);
    float getUnit_delayValue() const;
        float getUnit_delayPreValue() const;
    float update(float input);
private:
    float state;
    float pre_state;
};

#endif // UNIT_DELAY_H
