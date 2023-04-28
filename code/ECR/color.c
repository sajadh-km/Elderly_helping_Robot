
/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : color.c                              */
/*                                                                */
/******************************************************************/

#include "Arduino.h"
#include "ecr.h"

char check_color()
{
    int red_intensity  =0;
    int green_intensity=0;
    int blue_intensity =0;
    
    digitalWrite(RED_LED, HIGH);
    delay(10);
    red_intensity=analogRead(LDR);
    digitalWrite(GREEN_LED, HIGH);
    delay(10);
    green_intensity=analogRead(LDR);
    digitalWrite(blue_intensity, HIGH);
    delay(10);
    blue_intensity=analogRead(LDR);

    if(  red_intensity   < 200 && red_intensity   > 100 && 
         green_intensity < 200 && green_intensity > 100 && 
         blue_intensity  < 200 && blue_intensity  > 100 )
    {
        console_print("White");
        return (WHITE);
    }
    else if(  red_intensity   < 20 && red_intensity   > 10 && 
              green_intensity < 20 && green_intensity > 10 && 
              blue_intensity  < 20 && blue_intensity  > 10 )
    {
        console_print("black");
        return (BLACK);
    }
    if(  red_intensity   < 300 && red_intensity   > 200 && 
         green_intensity < 20 && green_intensity > 10 && 
         blue_intensity  < 20 && blue_intensity  > 10 )
    {
        console_print("Red");
        return (RED);
    }
    if(  red_intensity   < 20 && red_intensity   > 10 && 
         green_intensity < 300 && green_intensity > 200 && 
         blue_intensity  < 20 && blue_intensity  > 10 )
    {
        console_print("White");
        return (WHITE);
    }
    if(  red_intensity   < 20 && red_intensity   > 10 && 
         green_intensity < 20 && green_intensity > 10 && 
         blue_intensity  < 300 && blue_intensity  > 200 )
    {
        console_print("blue");
        return (BLUE);
    }
    if(  red_intensity   < 300 && red_intensity   > 200 && 
         green_intensity < 20 && green_intensity > 10 && 
         blue_intensity  < 300 && blue_intensity  > 200 )
    {
        console_print("Purple");
        return (PURPLE);
    }
}
