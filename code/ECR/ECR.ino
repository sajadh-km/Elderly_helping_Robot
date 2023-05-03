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

//#include "rtc.cpp"
#include "color.c"

#define   MOBILE_DEVICE            Serial1
#define   CONSOLE                  Serial

char                    message_received[30];
char                    num_of_task;

int                     hour=12;
int                     minute=30; 
ROBOT_TASK              trip[4];
char                    task_list=0b00000000;
    
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
    
    pinMode(BLUE_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED1, OUTPUT);
    pinMode(GREEN_LED2, OUTPUT);

    //  ***declare inputs***
    pinMode(LEFT_LINE_SENSOR, INPUT);
    pinMode(RIGHT_LINE_SENSOR, INPUT);
    pinMode(LEFT_END_SENSOR, INPUT);
    pinMode(RIGHT_END_SENSOR, INPUT);
    pinMode(SWITCH1, INPUT);
    move_forward(300);
    //move_back(1000);
    Serial.println(task_list, BIN);
}

void loop() 
{
      int                     res     =  -1;
      int                     i, j;
      char                    txt[40];     
      unsigned char           color;
      static unsigned long    lastTime = 0;
      unsigned long           currentTime = millis();
      char                    current_task_num=0;
      
      if (currentTime - lastTime >= 10) 
      {
          lastTime = currentTime;
          check_for_any_new_message();
      }
      get_time(&hour, &minute);
      sprintf(txt, "time: %d:%d\n", hour, minute);
      Serial.print(txt);
      
      
      #ifdef DEBUG_MODE
      for(i=0; i < num_of_task; i++)
      {
          j=i+1;
          console_print("**********************************************************************\n");
          sprintf(txt, "    task%d  |  time:  %d:%d  |  material: %d  |  destination: %d\n", j, trip[j].time.hour,trip[j].time.minute, trip[j].source_location, trip[j].dest_location);          
          console_print(txt);
          console_print("**********************************************************************\n");
      }
      #endif
      if(compare_task_time(& current_task_num))
      {      
          do_task(current_task_num);
          console_print("done task\n");
      }
      //

      // Serial.println(check_sensors(), BIN);
       
      
     
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

int compare_task_time(char* task_num)
{
    char i=0;
    for (i=0; i<4; i++)
    {
        if(trip[i].time.hour == hour && trip[i].time.minute == minute)
        {
            console_print("trip triggered\n");
            task_num =i;
            return (1);      
        }
    }
    return (0);
}
void do_task(char num)
{
    trip[num].time.hour=NULL;
    if(num==1)
    task_list |= 0b01111111;
    if(num==2)
    task_list |= 0b10111111;
    if(num==3)
    task_list |= 0b11011111;
    fetch_material(trip[num].source_location);
    supply(trip[num].dest_location);
    back_to_start_position();
}
void fetch_material(char num)
{
    unsigned char    received_color;
    while(! follow_line());
    console_print("line end\n");
    move_forward(3000);
    turn_full_left(3000);
    move_back(1000);    
    turn_90_degree();
    while(! follow_line());
    
    received_color = check_color();
    if(received_color == num)
    {
        turn_90_degree();
        while(! follow_line());
        take();
        turn_180_degree();
        while(! follow_line());
        turn_90_degree();        
    } 
}
void supply(char des)
{
    while( !follow_line());
    beep();
}
void back_to_start_position()
{

}
void turn_90_degree()
{
    turn_full_left(2000);
    while(check_sensors() != 8)
    turn_full_left(10);
}
void turn_180_degree()
{

}
void take()
{


}
void beep()
{
    static boolean state = HIGH;
    int    button=0;
    int    i;
    while(! button)
    {          
        digitalWrite(BUZZER, state);
        state = !state;
        for(i=0; i<200; i++)
        {
            button = digitalRead(SWITCH1);
            delay(1);
        }
    } 
    digitalWrite(BUZZER, LOW); 

}