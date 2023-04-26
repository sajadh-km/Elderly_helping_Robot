#include "Arduino.h"
/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : bluetooth_device.c                   */
/*                                                                */
/******************************************************************/

#include "ecr.h"

extern char message_received[30];
extern int message_available();
extern char message_read();
extern void message_reply(char* text);
extern void console_print(char* message);
int connect_bluetooth_device()
{
	int iterance=0;
	                                                         
	/*    wait here for getting any message from mobile app    */
    for(iterance=0; iterance<10000; iterance++) 
    {
	    if(message_available())
        return (1);
        delayMicroseconds(1000);	// one millisecond delay in each iterance
    }
    console_print("no message\n");
	  return (0);
}


int parse_message()
{
    int message_index = 0;                                   // Initialize message index to zero
    int wait;
    while ( message_index < 29)        // Check if there's any data available on Serial and if message index is less than 39
    {     
        wait=1000;
        while(!message_available() && wait)
        {
            wait--;
            delayMicroseconds(100);
        }
        char c = message_read();                             // Read the incoming character
        if (c != '\n')                                       // If the character is not a newline
        {
            message_received[message_index++] = c;           // Append the character to the message string and increment the message index
            if(message_index==5)
            {
              message_index=8;
              message_received[5]=':'  ;
              message_received[6]='0'  ;
              message_received[7]='0'  ;
            }
        }
        else                                                 // If the character is a newline
        {
            message_received[message_index] = '\0';          // Append a null terminator to the end of the message string
            message_index = 0;                               // Reset message index to zero for the next message
            break; 
        }	
    }
    return (0);
}


char check_for_any_new_message()
{     
    if(connect_bluetooth_device())
    {
        parse_message();
        console_print(message_received);
    }    
}

