
/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : color.c                              */
/*                                                                */
/******************************************************************/

#include "Arduino.h"
#include "ecr.h"

unsigned int intensity(int pin)
{
    unsigned int value=0;
    int i;
    for(i=0; i<50; i++)
    {
        value = value+ analogRead(A0);
        delay(5);
    }
    return (value/50);
}
void all_led_off()
{
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED1, HIGH);
    digitalWrite(GREEN_LED2, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
}

unsigned char check_color()
{
    char txt[40];
    unsigned int red_intensity  =0;
    unsigned int green_intensity=0;
    unsigned int blue_intensity =0;
    int total_of_all_color=0;
    int average_of_all_color=0;
    unsigned char result=0;

    
    digitalWrite(RED_LED, LOW);
    delay(100);
    red_intensity=map(intensity(LDR), 391, 900, 0, 100); //530 -666 
    //red_intensity=intensity(LDR); //530 -666 
    
    all_led_off();
    digitalWrite(GREEN_LED1, LOW);
    digitalWrite(GREEN_LED2, LOW);
    delay(100);
    green_intensity=map(intensity(LDR), 469, 1111, 0, 100);  //461 - 445 
    //green_intensity=intensity(LDR);  //461 - 445 

    all_led_off();
    digitalWrite(BLUE_LED, LOW);
    delay(100);
    blue_intensity=map(intensity(LDR), 390, 985, 0, 100);   //500 - 641
    //blue_intensity=intensity(LDR);   //500 - 641
    all_led_off();
    total_of_all_color = red_intensity + green_intensity + blue_intensity;
    average_of_all_color = total_of_all_color / 3;
    
    sprintf(txt, "R : %d, G : %d, B : %d Total: %d Avg: %d\n", red_intensity, green_intensity, blue_intensity, total_of_all_color, average_of_all_color);
    console_print(txt);
    
    if(red_intensity>90 && green_intensity>75 && blue_intensity>77)
    {
        console_print("White");
        //return (WHITE);                                         
    }
    else if(red_intensity<20 && green_intensity<20 && blue_intensity<10 )                        
    {
        console_print("black");
        //return (BLACK);
    }
    else if(red_intensity>75 && red_intensity<112 && green_intensity>7 && green_intensity<11 && blue_intensity>10 && blue_intensity<16)
    {
        console_print("red\n");
    }
    else if(red_intensity>35 && red_intensity<53 && green_intensity>58 && green_intensity<88 && blue_intensity>12 && blue_intensity<19)
    {
        console_print("green\n");
    }
    else if(red_intensity>13 && red_intensity<21 && green_intensity>52 && green_intensity<79 && blue_intensity>64 && blue_intensity<97)
    {
        console_print("blue\n");
    }
    else if(red_intensity>78 && red_intensity<118 && green_intensity>16 && green_intensity<25 && blue_intensity>48 && blue_intensity<72)
    {
        console_print("magenta\n");
    }
    else if(red_intensity>80 && red_intensity<120 && green_intensity>63 && green_intensity<95 && blue_intensity>13 && blue_intensity<20)
    {
        console_print("yellow\n");
    }
    /*
    else if(red_intensity>88 && red_intensity<98 && green_intensity>57 && green_intensity<70 && blue_intensity<58 && blue_intensity>48)
    {
        console_print("orange\n");
    }
    else if(red_intensity>50 && red_intensity<69 && green_intensity>45 && green_intensity<55 && blue_intensity<94 && blue_intensity>75)
    {
        console_print("light blue\n");
    }
    else if(red_intensity>53 && red_intensity<63 && green_intensity>54 && green_intensity<64 && blue_intensity<84 && blue_intensity>65)
    {
        console_print("light green\n");
    }
    */
    else if(red_intensity>36 && red_intensity<55 && green_intensity>16 && green_intensity<24 && blue_intensity>56 && blue_intensity<84)
    {
        console_print("violet\n");
    }
    else
    {
        console_print("other\n");
    }

    return (result);
    
}
