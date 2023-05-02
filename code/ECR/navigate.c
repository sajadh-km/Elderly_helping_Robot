/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : navigate.c                           */
/*                                                                */
/******************************************************************/
#include "Arduino.h"
#include "ecr.h"

/*
    0 0 0 0
    0 0 0 1
    0 0 1 0
    0 0 1 1 
    0 1 0 0 
    0 1 0 1
    0 1 1 0
    0 1 1 1 
    1 0 0 0 
    1 0 0 1
    1 0 1 0           10
    1 0 1 1           11
    1 1 0 0           12
    1 1 0 1           13
    1 1 1 0           14
    1 1 1 1           15
*/

char follow_line()
{
    char robot_position=0;
    char txt[10];
    robot_position = check_sensors();
    if(robot_position == 2)
    turn_left(5);
    else if(robot_position == 1 || robot_position == 3)
    turn_full_left(5);
    else if(robot_position == 4)
    turn_right(5);
    else if(robot_position == 8 || robot_position == 12)
    turn_full_right(5);
    else if(robot_position == 6)
    move_forward(10);
    else if(robot_position == 15 )
    return (1);
    else
    move_forward(2);
    //console_print("bak\n");
    //move_back(50);
    return (0);
}


char check_sensors()
{
    char    value=0;
    if(digitalRead(LEFT_END_SENSOR))
    value = value | 0b00000001;
    if(digitalRead(LEFT_LINE_SENSOR))
    value = value | 0b00000010;
    if(digitalRead(RIGHT_LINE_SENSOR))
    value = value | 0b00000100;
    if(digitalRead(RIGHT_END_SENSOR))
    value = value | 0b00001000;
    
    return (value);
}