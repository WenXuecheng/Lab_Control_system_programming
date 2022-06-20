#include "plant.h"
#include "inputsignal.h"
#include "blocks/gain/gain.h"
Plant::Plant()
{


    gain_0 = new gain(0.1);//first gain0
    gain_1 = new gain(1.0 );
    gain_2 = new gain(0.0 );
    gain_3 = new gain(-0.0015);
    gain_4 = new gain(0.01);
    gain_5 = new gain(1.0);
    gain_6 = new gain(-0.0055);
    gain_7 = new gain(0.0);
    gain_8 = new gain(0.01);
    gain_9 = new gain(0.9965);
    gain_10 = new gain(0.015);
    gain_11 = new gain(0.005);
    gain_12 = new gain(0.025);
    //init out of delay
    delay_x1 = new Unit_delay(0);
    delay_x2 = new Unit_delay(0);
    delay_x3 = new Unit_delay(0);
    //init  output
    plant_value_x1 = delay_x1->getUnit_delayValue();
    plant_value_x2 = delay_x1->getUnit_delayValue();
    plant_value_x3 = delay_x1->getUnit_delayValue();
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
    plant_value_x1 = delay_x1->update(gain_1->update(plant_value_x1) + gain_2->update(plant_value_x2) + gain_3->update(plant_value_x3) + gain_10->update(input));
    plant_value_x2 = delay_x2->update(gain_4->update(delay_x1->getUnit_delayPreValue()) + gain_5->update(plant_value_x2) + gain_6->update(plant_value_x3) + gain_11->update(input));
    plant_value_x3 = delay_x3->update(gain_7->update(delay_x1->getUnit_delayPreValue()) + gain_8->update(delay_x2->getUnit_delayPreValue()) + gain_9->update(plant_value_x3) + gain_12->update(input));
    output = gain_0->update(plant_value_x3);
    return output;
}
