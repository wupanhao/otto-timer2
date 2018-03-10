// receiver.pde
//
// Simple example of how to use VirtualWire to receive messages
// Implements a simplex (one-way) receiver with an Rx-B1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: receiver.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $
//#include <Servo.h>
//#include <EEPROM.h>
#include "Otto2.h"
Otto2 otto2;
#include <VirtualWire.h>
  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]
int count;
void setup()
{
    otto2.init(2,3,4,5);
    otto2.home();
    Serial.begin(9600);  // Debugging only
    Serial.println("setup"); //Prints "Setup" to the serial monitor
    vw_set_rx_pin(13);       //Sets pin D12 as the RX Pin
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(4000);      // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;
        digitalWrite(13, true);  // Flash a light to show received good message
  // Message with a good checksum received, dump it.
  Serial.print("Got: ");
  
  
            int c = (buf[i])-'0';
            Serial.print(c);
      Serial.print(" ");
 
        count++;
       // Serial.print(count);
  Serial.println("");
//        digitalWrite(13, false);
enum command{WALK=1,TURNR,TURNL,UP};
        
        switch(c){
        case WALK:otto2. walk(4,1000,FORWARD);break; 
        case TURNR:otto2. turn(4,2000,RIGHT);break;
        case TURNL:otto2. turn(4,2000,LEFT);break;
        case UP:otto2. updown(1,1000,20);break;
       
    }
}
}
    
