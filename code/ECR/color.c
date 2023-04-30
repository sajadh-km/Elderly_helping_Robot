
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
    for(i=0; i<10; i++)
    {
        value = value+ analogRead(A0);
        delay(2);
    }
    return (value/10);
}
void all_led_off()
{
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED1, LOW);
    digitalWrite(GREEN_LED2, LOW);
    digitalWrite(BLUE_LED, LOW);
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

    all_led_off();
    digitalWrite(RED_LED, HIGH);
    delay(100);
    red_intensity=map(intensity(LDR), 0, 697, 0, 100); //530 -666 
    //red_intensity=intensity(LDR); //530 -666 
    
    all_led_off();
    digitalWrite(GREEN_LED1, HIGH);
    digitalWrite(GREEN_LED2, HIGH);
    delay(100);
    green_intensity=map(intensity(LDR), 0, 309, 0, 100);  //461 - 445 
    //green_intensity=intensity(LDR);  //461 - 445 

    all_led_off();
    digitalWrite(BLUE_LED, HIGH);
    delay(100);
    digitalWrite(BLUE_LED, LOW);
    blue_intensity=map(intensity(LDR), 0, 234, 0, 100);   //500 - 641
    //blue_intensity=intensity(LDR);   //500 - 641
    
    total_of_all_color = red_intensity + green_intensity + blue_intensity;
    average_of_all_color = total_of_all_color / 3;
    
    sprintf(txt, "R : %d, G : %d, B : %d Total: %d Avg: %d\n", red_intensity, green_intensity, blue_intensity, total_of_all_color, average_of_all_color);
    console_print(txt);
    
    if(red_intensity>80 && green_intensity>80 && blue_intensity>80)
    {
        console_print("White");
        //return (WHITE);                                         
    }
    else if(red_intensity<88 && green_intensity<52 && blue_intensity<61 )                        
    {
        console_print("black");
        //return (BLACK);
    }
    else if(red_intensity>88 && red_intensity<98 && green_intensity>52 && green_intensity<68 && blue_intensity<80 && blue_intensity>68)
    {
        console_print("red\n");
    }
    else if(red_intensity>56 && red_intensity<82 && green_intensity>32 && green_intensity<44 && blue_intensity<54 && blue_intensity>44)
    {
        console_print("green\n");
    }
    else if(red_intensity>40 && red_intensity<52 && green_intensity>22 && green_intensity<32 && blue_intensity<69 && blue_intensity>55)
    {
        console_print("blue\n");
    }
    else if(red_intensity>77 && red_intensity<92 && green_intensity>32 && green_intensity<42 && blue_intensity<80 && blue_intensity>68)
    {
        console_print("magenta\n");
    }
    else if(red_intensity>90 && red_intensity<100 && green_intensity>99 && green_intensity<109 && blue_intensity<59 && blue_intensity>49)
    {
        console_print("yellow\n");
    }
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
    else if(red_intensity>57 && red_intensity<67 && green_intensity>28 && green_intensity<48 && blue_intensity<79 && blue_intensity>66)
    {
        console_print("violet\n");
    }
    else
    {
        console_print("other\n");
    }

    return (result);
    
}
