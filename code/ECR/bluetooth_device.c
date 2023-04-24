/*********************************************************/
/*                                                       */
/*          project : Elderly care robot                 */
/*          file    : bluetooth_device.c                 */
/*                                                       */
/*********************************************************/

#include "ecr.h"
#include <Arduino.h>

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
int parse_message()
{
    //massage_received = MOBILE_DEVICE.read();
    	
}	