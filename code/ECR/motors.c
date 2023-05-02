/*********************************************************/
/*                                                       */
/*          project : Elderly care robot                 */
/*          file    : motors.c                           */
/*                                                       */
/*********************************************************/

#include "ecr.h"
//#include <Arduino.h>
extern void console_print(char* message);
int stop_motors()
{
    digitalWrite(LEFT_MOTOR_PIN_1, LOW);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
	  digitalWrite(RIGHT_MOTOR_PIN_1, LOW);
  	digitalWrite(RIGHT_MOTOR_PIN_2, LOW); 
    delay(5); 
    return (0);	
}

int move_forward(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
  	digitalWrite(RIGHT_MOTOR_PIN_1, HIGH);
  	digitalWrite(RIGHT_MOTOR_PIN_2, LOW);
    console_print("fwd\n");
  	delay(duration);
  	stop_motors();
	  return(0);
}

int move_back(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, LOW);
    digitalWrite(LEFT_MOTOR_PIN_2, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_1, LOW);
  	digitalWrite(RIGHT_MOTOR_PIN_2, HIGH);
    console_print("bak\n");
	  delay(duration);
	  stop_motors();
	  return(0);
}

int turn_left(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
	  //digitalWrite(RIGHT_MOTOR_PIN_1, LOW);
	  //digitalWrite(RIGHT_MOTOR_PIN_2, HIGH);
    console_print("left\n");
	  delay(duration);
	  stop_motors();
	  return(0);
}
int turn_full_left(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
	  digitalWrite(RIGHT_MOTOR_PIN_1, LOW);
	  digitalWrite(RIGHT_MOTOR_PIN_2, HIGH);
    console_print("left\n");
	  delay(duration);
	  stop_motors();
	  return(0);
}

int turn_right(int duration)
{
    //digitalWrite(LEFT_MOTOR_PIN_1, LOW);
    //digitalWrite(LEFT_MOTOR_PIN_2, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_1, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_2, LOW);
    console_print("right\n");
	  delay(duration);
	  stop_motors();
	  return(0);
}
int turn_full_right(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, LOW);
    digitalWrite(LEFT_MOTOR_PIN_2, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_1, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_2, LOW);
    console_print("right\n");
	  delay(duration);
	  stop_motors();
	  return(0);
}