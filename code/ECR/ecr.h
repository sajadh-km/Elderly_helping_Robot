/**********************************************************************/
/*                                                                    */
/*                       project : Elderly care robot                 */
/*                       file    : ecr.h                              */
/*                                                                    */
/**********************************************************************/

#ifndef  _ECR_H_
#define  _ECR_H_

#include <time.h>
#include <Arduino.h>

//#include <HardwareSerial.h>

//        ***motor pins are declared here***       

#define LEFT_MOTOR_PIN_1        9
#define LEFT_MOTOR_PIN_2        10
#define RIGHT_MOTOR_PIN_1       11
#define RIGHT_MOTOR_PIN_2       12

//        ***LED pins are declared here***        

#define RED_LED                  22
#define GREEN_LED1               23
#define GREEN_LED2               24           
#define BLUE_LED                 25

//        ***IR line sensors***

#define LEFT_LINE_SENSOR         8
#define RIGHT_LINE_SENSOR        7

//        ***othr pins***

#define LDR                     A0

//



//        ***locations are defined here***

#define FOOD                     1
#define WATER                    2
#define MEDICINE                 3
#define BOOK                     4
#define BED_1                    5
#define BED_2                    6
#define BED_3                    7

//        ***Colors defined here***
/*
#define RED                      0x04
#define GREEN                    0x02
#define BLUE                     0x01
#define MAGENTA                  0x05
#define CYAN                     0x06
#define YELLOW                   0x03
#define WHITE                    0x07
#define BLACK                    0x08
*/
enum color_code {
  BLACK,
  WHITE,
  RED,
  GREEN,
  BLUE,
  MAGENTA,
  YELLOW,
  ORANGE,
  LIGHT_BLUE,
  LIGHT_GREEN,
  VIOLET
};


//        ***line sensor positions***

#define ON_LEFT                  0b00000001
#define ON_RIGHT                 0b00000010
#define ON_LINE                  0b00000011
#define OUTSIDE_LINE             0b00000000 


typedef struct task_time {
    int hour;
    int minute;
} TASK_TIME;

typedef struct task {
    TASK_TIME time;                  // time of trip (using time_t data type)
    int source_location;    // source location (using short int data type)
    int dest_location;      // destination location (using short int data type)
}ROBOT_TASK;



int connect_bluetooth_device();
char create_task();
char get_message();
int move_forward(int duration);
int move_back(int duration);
int stop_motors();
int turn_left(int duration);
int turn_right(int duration);
char check_sensors();
void follow_line();
int get_time();
unsigned char


 check_color();

#endif