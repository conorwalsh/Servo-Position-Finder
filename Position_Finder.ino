/*********************************************************************
**********************************************************************

 Conor Walsh 2013
  Website: http://www.conorwalsh.net
  GitHub:  https://github.com/conorwalsh
  
  Version 1.5
  
  First created: 6th September 2013
  Last modified: 13th October 2013

  Description: This code was created as a piece of testing software
               that I used to determine positions for a servo motor
               connected to an Arduino where the servo needed to be
               positioned very precisely. 
  
 *************************** LICENCE *****************************
 
 Copyright (c) 2013 Conor Walsh

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  
******************************************************************
*****************************************************************/

//Include Servo libraries
#include <Servo.h> 

//Declare the servo
Servo myservo;
 
// variable to store the servos position
int pos;

//How long before the next cycle starts
int cycledelay = 1500;

//How long before the increment changes
int readdelay = 500;

//The minimum servo motor value
int minpos = 20;

//The maximum servo motor value
int maxpos = 160;

//Increment for the servo motor
int stepval = 1;
 
void setup(){ 
  //Start Serial
  Serial.begin(9600);
  //Attach the servo to pin 5
  myservo.attach(5);
  Serial.println("Ready");
  Serial.println("");
} 
 
 
void loop(){ 
  //For loop - loop while pos is greater than or equal to the min pos pos - increment
  for(pos = maxpos; pos >= minpos; pos -= stepval){                                
    //Write the pos value to the servo
    myservo.write(pos);
    //Print the position value to the serial
    Serial.println(pos);
    //Wait for the read delay time
    delay(readdelay);
  } 
  
  //Wait for the specified ms
  delay(cycledelay);
  
  //For loop - loop while pos is less than or equal to the max pos pos + increment
  for(pos = minpos; pos <= maxpos; pos += stepval){
    //Write the pos value to the servo
    myservo.write(pos);
    //Print the position value to the serial
    Serial.println(pos);
    //Wait for the read delay time
    delay(readdelay);
  } 
  
  //Wait for the specified ms
  delay(cycledelay);
  
}
