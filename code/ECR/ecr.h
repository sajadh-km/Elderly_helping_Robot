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

#define LEFT_MOTOR_PIN_1        10
#define LEFT_MOTOR_PIN_2        11
#define RIGHT_MOTOR_PIN_1       12
#define RIGHT_MOTOR_PIN_2       13

//

//#define   MOBILE_DEVICE         Serial1

//        ***locations are defined here***

#define FOOD                     1
#define WATER                    2
#define MEDICINE                 3
#define BOOK                     4
#define BED_1                  5
#define BED_2                  6
#define BED_3                  7

//        ***LED pins are declsred here***        

#define RED                      1
#define GREEN                    2
#define BLUE                     3


typedef struct task {
    time_t time;                  // time of trip (using time_t data type)
    short int source_location;    // source location (using short int data type)
    short int dest_location;      // destination location (using short int data type)
}ROBOT_TASK;


int connect_bluetooth_device();
char create_task();
char get_message();

#endif