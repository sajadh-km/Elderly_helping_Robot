/*********************************************************/
/*                                                       */
/*          project : Elderly care robot                 */
/*          file    : motors.c                           */
/*                                                       */
/*********************************************************/

#include "ecr.h"
//#include <Arduino.h>

int stop_motors()
{
    digitalWrite(LEFT_MOTOR_PIN_1, LOW);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
	  digitalWrite(RIGHT_MOTOR_PIN_1, LOW);
  	digitalWrite(RIGHT_MOTOR_PIN_2, LOW); 
    delay(10); 
    return (0);	
}

int move_forward(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
  	digitalWrite(RIGHT_MOTOR_PIN_1, HIGH);
  	digitalWrite(RIGHT_MOTOR_PIN_2, LOW);
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
	  delay(duration);
	  stop_motors();
	  return(0);
}

int turn_left(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN_2, LOW);
	  digitalWrite(RIGHT_MOTOR_PIN_1, LOW);
	  digitalWrite(RIGHT_MOTOR_PIN_2, HIGH);
	  delay(duration);
	  stop_motors();
	  return(0);
}

int turn_right(int duration)
{
    digitalWrite(LEFT_MOTOR_PIN_1, LOW);
    digitalWrite(LEFT_MOTOR_PIN_2, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_1, HIGH);
	  digitalWrite(RIGHT_MOTOR_PIN_2, LOW);
	  delay(duration);
	  stop_motors();
	  return(0);
}