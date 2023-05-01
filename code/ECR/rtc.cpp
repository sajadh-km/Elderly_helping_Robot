
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
virtuabotixRTC myRTC(6, 7, 8);



int get_time(int* hr, int* min)  
{
  #if 1   //test
  static int dummy_min=0;
  dummy_min++;
  *hr    = 12;
  *min   = dummy_min;
  #endif
  myRTC.updateTime();
  /*
  *hr = myRTC.hours;
  *min= myRTC.minutes;
  */
  return (0);
}
