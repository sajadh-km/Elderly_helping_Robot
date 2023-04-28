/***************************************************************************************/
/*                                                                                     */
/*          project       : Elderly care robot                                         */
/*          file          : ECR.c                                                      */
/*          working method:                                                            */
/*          > After switching on the, the robot will wait for any instruction          */
/*            from user                                                                */
/*          > On this time user can send a message to robot via (bluetooth)            */ 
/*            mobile app.                                                              */
/*          > Message will be in fixed format (text).                                  */
/*          > Message format : <material> <space> <destination bed no> <space>         */
/*            <time>                                                                   */
/*                                                                                     */
/***************************************************************************************/



#include "ecr.h"

#include "motors.c"
#include "bluetooth_device.c"
#include "navigate.c"
/*
#include "rtc.cpp"
#include "color.c"
*/
#define   MOBILE_DEVICE            Serial1
#define   CONSOLE                  Serial

char message_received[30];
char num_of_task;
ROBOT_TASK trip[4];

#if 0
int connect_bluetooth_device()
{
	int iterance=0;
	                                                         
	/*    wait here for getting any message from mobile app    */
    for(iterance=0; iterance<30000; iterance++) 
    {
	    if(MOBILE_DEVICE.available())
        return (1);
        delayMicroseconds(1000);	// one millisecond delay in each iterance
    }
	return (0);
}
#endif

void setup() 
{
    MOBILE_DEVICE.begin(9600);
    CONSOLE.begin(19200);
    CONSOLE.println("ECR");
    memset(message_received, '\0', sizeof(message_received));
    //  ***declare outputs***
    pinMode(LEFT_MOTOR_PIN_1, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN_1, OUTPUT);
    pinMode(LEFT_MOTOR_PIN_2, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN_2, OUTPUT);

    //  ***declare inputs***
    pinMode(LEFT_LINE_SENSOR, INPUT);
    pinMode(RIGHT_LINE_SENSOR, INPUT);
}

void loop() 
{
      int res =  -1;
      int i, j;
      char txt[40];
      static unsigned long lastTime = 0;
      unsigned long currentTime = millis();
      if (currentTime - lastTime >= 10) 
      {
          lastTime = currentTime;
          check_for_any_new_message();
      }
      get_time();
      for(i=0; i < num_of_task; i++)
      {
          j=i+1;
          console_print("**********************************************************************\n");
          sprintf(txt, "    task%d  |  time:  %d:%d  |  material: %d  |  destination: %d\n", j, trip[j].time.hour,trip[j].time.minute, trip[j].source_location, trip[j].dest_location);          
          console_print(txt);
          console_print("**********************************************************************\n");
      }
}

int message_available()
{
    return(MOBILE_DEVICE.available());
}

char message_read()
{
    return(MOBILE_DEVICE.read());
}
void message_reply(char* text)
{
    Serial1.print(text);
}
void console_print(char* message) 
{
  Serial.println(message);
}
void print_binary(char message)
{
    CONSOLE.print(message, BIN);  
}

