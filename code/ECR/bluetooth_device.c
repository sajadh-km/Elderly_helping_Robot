
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
extern char num_of_task;
extern char task_list;
    
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
    console_print("no new messages\n");
	  return (0);
}


int parse_message()
{
    int message_index = 0;                                   // Initialize message index to zero
    int wait;
    memset(message_received, 0x00, sizeof(message_received));    
    while ( message_index < 29)        // Check if there's any data available on Serial and if message index is less than 39
    {     
        wait=1000;
        while(!message_available() && wait)
        {
            wait--;
            delayMicroseconds(100);
        }
        if(! wait)
        break;
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
            message_received[message_index] = '\0';          // Append a nullset to the end of the message string
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
        console_print("\nnew message received: ");
        console_print(message_received);
        create_task();
    }   
    return (0); 
}

char create_task()
{
    char num;
    char i,j;
    int hour;
    int minute;
    bool message_invalid=0;
    char txt[20];
    char starting_address_of_destination ;
    memset (txt, '\0', 20);
    num=get_message();
    num_of_task= num;
    //    ***get task time here***
    txt[0] = message_received[0];
    txt[1] = message_received[1];
    hour = atoi(txt);
    if(hour < 25 && hour >=0)
    trip[num].time.hour=hour;
    else 
    return (-1);
    
    memset (txt, '\0', 20);
    
    txt[0] = message_received[3];
    txt[1] = message_received[4];
    minute = atoi(txt);
    if(minute < 60 && minute >=0)
    trip[num].time.minute=minute;
    else 
    return (-1);

    
    memset (txt, '\0', 20);
    for(i=9; i<19; i++)
    {
      j=i-9;
      starting_address_of_destination =i +1;
      if(message_received[i]==' ')
      break;
      txt[j]=message_received[i];
    }
    /***   FOOD | WATER | MEDICINE | BOOK   ***/
    if( !(strcmp(txt, "FOOD")) )
    trip[num].source_location= FOOD;
    else if ( !(strcmp(txt, "MEDICINE")))
    trip[num].source_location= MEDICINE;
    else if( !(strcmp(txt, "WATER")))
    trip[num].source_location= WATER;
    else
    return(-1);
    console_print("task");
    print_binary(num);
    console_print("\n");
    console_print("src:");
    print_binary(trip[num].source_location);
    memset (txt, '\0', 20);
    for(i= starting_address_of_destination; i < 30; i++)
    {
        j= i- starting_address_of_destination ;
        if( message_received[i] == ';')
        {
            txt[j] = message_received[i];
            break;
        }
        
        txt[j] = message_received[i];
        
    }
    console_print(txt);  
    if( !(strcmp(txt, "BED1")) )
    {
        trip[num].dest_location= BED_1;
    }
    else if( !(strcmp(txt, "BED2")) )
    {
        trip[num].dest_location= BED_2;  
    }
    else
    {
        console_print("no destination\n");
        return (-1) ;
    }
    
    console_print(" des:");
    print_binary(trip[num].dest_location);
    console_print("\n");
    return (0);
}

char get_message()
{
    #define TASK_LIST_LOG  
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
        //console_print(msg);                   
        #endif             
    }
    else if(! (task_list & 0b01000000))
    {
        task_number=2;
        task_list = task_list | 0b01000000 ;
        #ifdef TASK_LIST_LOG
        sprintf(msg, "\nnum2");
        //console_print(msg);                  
        #endif              
    }
    else if(! (task_list & 0b00100000))
    {
        task_number=3;
        task_list = task_list | 0b00100000 ;
        #ifdef TASK_LIST_LOG
        sprintf(msg, "\nnum3");
        //console_print(msg);                
        #endif
    }
    else
    {
        console_print("tasks filled");
        message_reply("tasks filled");
    }
    //#ifdef TASK_LIST_LOG
    sprintf(msg, "\nList: ");
    //console_print(msg);
    //print_binary(task_list);
    //console_print("\n");
    //#endif
    return (task_number);
}