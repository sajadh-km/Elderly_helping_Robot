#include "pins_arduino.h"

/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : sound.c                              */
/*                                                                */
/******************************************************************/

#include "Arduino.h"
#include "ecr.h"

void fr_1()
{
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(100);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(100);
}
void fr_2()
{
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(200);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(200);
}
void fr_3()
{
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(300);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(300);
}

void tone1()
{
    int    i;
    for(i=0; i<600; i++)
    fr_1();
    for(i=0; i<500; i++)
    fr_2();
    for(i=0; i<100; i++)
    fr_3();
}
void tone2()
{
    int    i;
    for(i=0; i<100; i++)
    fr_3();
    for(i=0; i<100; i++)
    fr_1();
    for(i=0; i<100; i++)
    fr_3();
}
void beep()
{
    static boolean state = HIGH;
    int    button=0;
    int    i;
    button = digitalRead(SWITCH1);
    while(button)
    {          
        digitalWrite(BUZZER, state);
        state = !state;
        for(i=0; i<20; i++)
        {
            button = digitalRead(SWITCH1);
            delay(1);
        }
    } 
    digitalWrite(BUZZER, LOW); 
}