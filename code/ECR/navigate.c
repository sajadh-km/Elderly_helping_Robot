#include "Arduino.h"
#include "ecr.h"
/*
extern turn_left(int duration);
extern turn_right(int duration);
extern move_back(int duration);
extern move_forward(int duration);
*/
void follow_line()
{
    char robot_position=0;
    char txt[10];
    robot_position = check_sensors();
    if(robot_position == ON_LEFT)
    turn_right(50);
    else if(robot_position == ON_RIGHT)
    turn_left(50);
    else if(robot_position == ON_LINE)
    move_forward(10);
    else
    move_back(50);
    //sprintf(txt, "=%d  \n", robot_position);
    //console_print(txt);
}


char check_sensors()
{
    char    value=0;
    if(digitalRead(LEFT_LINE_SENSOR))
    value = value | 0b00000001;
    if(digitalRead(RIGHT_LINE_SENSOR))
    value = value | 0b00000010;
    return (value);
}