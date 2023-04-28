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

#define RED_LED                  2
#define GREEN_LED                3
#define BLUE_LED                 4            

//        ***IR line sensors***

#define LEFT_LINE_SENSOR         2
#define RIGHT_LINE_SENSOR        3

//        ***othr pins***

#define LDR                     5

//

//#define   MOBILE_DEVICE         Serial1

//        ***locations are defined here***

#define FOOD                     1
#define WATER                    2
#define MEDICINE                 3
#define BOOK                     4
#define BED_1                    5
#define BED_2                    6
#define BED_3                    7

//        ***Colors defined here***

#define RED                      1
#define GREEN                    2
#define BLUE                     3
#define PURPLE                   4
#define WHITE                    5
#define BLACK                    6


//        ***line sensor positions***

#define ON_LEFT                  0b00000001
#define ON_RIGHT                 0b00000010
#define ON_LINE                  0b00000011
#define OUTSIDE_LINE             0b00000000 


typedef struct task_time {
    char hour;
    char minute;
} TASK_TIME;

typedef struct task {
    TASK_TIME time;                  // time of trip (using time_t data type)
    short int source_location;    // source location (using short int data type)
    short int dest_location;      // destination location (using short int data type)
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
char check_color();

#endif