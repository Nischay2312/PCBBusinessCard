/****************************************************************************************************************************
  basic_pwm.ino
  For RP2040 boards
  Written by Dr. Benjamin Bird

  A basic example to get you up and running.

  Library by Khoi Hoang https://github.com/khoih-prog/RP2040_PWM
  Licensed under MIT license

  The RP2040 PWM block has 8 identical slices. Each slice can drive two PWM output signals, or measure the frequency
  or duty cycle of an input signal. This gives a total of up to 16 controllable PWM outputs. All 30 GPIO pins can be driven
  by the PWM block
*****************************************************************************************************************************/

#define _PWM_LOGLEVEL_        3
#include "RP2040_PWM.h"

//creates pwm instance
RP2040_PWM* PWM_Instance;

float frequency;
float dutyCycle;

#define pinToUse      16

void setup()
{
  //assigns pin 25 (built in LED), with frequency of 20 KHz and a duty cycle of 0%
  PWM_Instance = new RP2040_PWM(pinToUse, 100000, 0);
}

void loop()
{
  frequency = 1000*1000;
  dutyCycle = 50;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(1000);
  for(int i = 1; i <= 100; i++){
    PWM_Instance->setPWM(pinToUse, frequency, i);
    delay(8);
  }
  delay(100);
  for(int i = 100; i >= 1; i--){
    PWM_Instance->setPWM(pinToUse, frequency, i);
    delay(8);
  }
  delay(1000);
  dutyCycle = 50;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(5000);
}
