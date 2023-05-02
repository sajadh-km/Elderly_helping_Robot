
/******************************************************************/
/*                                                                */
/*                 project : Elderly care robot                   */
/*                 file    : rtc.cpp                              */
/*                                                                */
/******************************************************************/

#include "Arduino.h"
#include "ecr.h"
#include <virtuabotixRTC.h>
extern void console_print(char* message);
// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(2, 3, 4);



int get_time(int* hr, int* min)  
{
  myRTC.updateTime();
  
  *hr = myRTC.hours;
  *min= myRTC.minutes;
  
  return (0);
}
