
/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : bluetooth_device.c                   */
/*                                                                */
/******************************************************************/
#include "Arduino.h"
#include "ecr.h"

extern char message_received[30];
extern int message_available();
extern char message_read();
extern void message_reply(char* text);
extern void console_print(char* message);
extern void print_binary(char message);
extern ROBOT_TASK trip[4];
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
        create_task();
    }    
}

char create_task()
{
    char num;
    char i,j;
    char action[20];
    memset (action, 0x00, 10);
    num=get_message();
    console_print("\naction:");
    
    for(i=9; i<19; i++)
    {
      j=i-9;
      if(message_received[i]==' ')
      break;
      action[j]=message_received[i];
    }
    console_print(action);

}
char get_message()
{
    //#define TASK_LIST_LOG  
    static char task_list=0b00000000;
    char task_number;
    #ifdef TASK_LIST_LOG
    char msg[20];
    memset(msg, 0x00, 20);
    #endif
    if(! (task_list && 0b10000000))
    {
        task_number=1;
        task_list = task_list | 0b10000000 ;
        #ifdef TASK_LIST_LOG
        sprintf(msg, "\nnum1");
        console_print(msg);                   
        #endif             
    }
    else if(! (task_list & 0b01000000))
    {
        task_number=2;
        task_list = task_list | 0b01000000 ;
        #ifdef TASK_LIST_LOG
        sprintf(msg, "\nnum2");
        console_print(msg);                  
        #endif              
    }
    else if(! (task_list & 0b00100000))
    {
        task_number=3;
        task_list = task_list | 0b00100000 ;
        #ifdef TASK_LIST_LOG
        sprintf(msg, "\nnum3");
        console_print(msg);                
        #endif
    }
    #ifdef TASK_LIST_LOG
    sprintf(msg, "\nList: ");
    console_print(msg);
    print_binary(task_list);
    console_print("\n");
    #endif
    return (task_number);
}