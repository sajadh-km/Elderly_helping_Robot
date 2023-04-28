
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



int get_time()  
{
  myRTC.updateTime();
  char txt[10];
  sprintf(txt, "\n%d:%d\n", myRTC.hours, myRTC.minutes);
  console_print(txt);
  return (0);
}
