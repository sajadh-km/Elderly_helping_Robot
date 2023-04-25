/*******************************************************************************/
/*                                                                             */
/*          project       : Elderly care robot                                 */
/*          file          : ECR.c                                              */
/*          working method:                                                    */
/*          > After switching on the, the robot will wait for any instruction  */
/*            from user                                                        */
/*          > On this time user can send a message to robot via (bluetooth)    */ 
/*            mobile app.                                                      */
/*          > Message will be in fixed format (text).                          */
/*          > Message format : <material> <space> <destination bed no> <space> */
/*            <time>                                                           */
/*                                                                             */
/*******************************************************************************/



#include "ecr.h"
#include "motors.c"
#include "bluetooth_device.c"

#define   MOBILE_DEVICE            Serial1
#define   CONSOLE                  Serial

char message_received[30];

ROBOT_TASK trip_1;
ROBOT_TASK trip_2;
ROBOT_TASK trip_3;
ROBOT_TASK trip_4;

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
    if(connect_bluetooth_device())
    {
        parse_message();
    }
}

void loop() 
{
      int res =  -1;
      res= stop_motors();
      res= move_forward(2000);
}

int message_available()
{
    return(MOBILE_DEVICE.available());
}

char message_read()
{
    return(MOBILE_DEVICE.read());
}
void console_print(char* message) 
{
  Serial.print(message);
}
