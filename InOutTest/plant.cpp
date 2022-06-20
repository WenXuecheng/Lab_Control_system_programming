#include "plant.h"
#include "inputsignal.h"
#include "blocks/gain/gain.h"
Plant::Plant()
{
    integral_x1 = new Integral(0,0); // first integral
    integral_x2 = new Integral(0,0);
    integral_x3 = new Integral(0,0);

    gain_0 = new gain(0.1);//first gain0
    gain_1 = new gain(1.5);
    gain_2 = new gain(-0.15);
    gain_3 = new gain(0.5);
    gain_4 = new gain(-0.55);
    gain_5 = new gain(-0.35);
    gain_6 = new gain(2.5);

    //init out of integral
    plant_value_x1 = integral_x1->getStateValue();
    plant_value_x2 = integral_x2->getStateValue();
    plant_value_x3 = integral_x3->getStateValue();

    //init  output
    output = gain_0->update(plant_value_x3);
}

//return state value of x1 x2 x3
float Plant::getPlantValue_x1() const {
    return this->plant_value_x1;
}
float Plant::getPlantValue_x2() const {
    return this->plant_value_x2;
}
float Plant::getPlantValue_x3() const {
    return this->plant_value_x3;
}
float Plant::getPlantValue_output() const {
    return this->output;
}

float Plant::update(float input,float dt) {
    plant_value_x1 = integral_x1->update(gain_1->update(input)+gain_2->update(plant_value_x3),dt);
    plant_value_x2 = integral_x2->update(gain_3->update(input) +plant_value_x1+gain_4->update(plant_value_x3),dt);
    plant_value_x3 = integral_x3->update(plant_value_x2+gain_5->update(plant_value_x3)+gain_6->update(input),dt);
    output = gain_0->update(plant_value_x3);

    return output;
}
