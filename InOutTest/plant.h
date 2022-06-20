#ifndef PLANT_H
#define PLANT_H
#include "inputsignal.h"
#include "integral.h"
#include "blocks/gain/gain.h"
class Plant
{
public:
    Plant();
    float getPlantValue_x1() const;
    float getPlantValue_x2() const;
    float getPlantValue_x3() const;
    float getPlantValue_output() const;
    float update(float input,float dt);
private:
    float plant_value_x1;
    float plant_value_x2;
    float plant_value_x3;
    float output;



    //integrals of plant
    Integral *integral_x1;
    Integral *integral_x2;
    Integral *integral_x3;


    // gains of plant
    gain *gain_0;
    gain *gain_1;
    gain *gain_2;
    gain *gain_3;
    gain *gain_4;
    gain *gain_5;
    gain *gain_6;

};


#endif // PLANT_H
