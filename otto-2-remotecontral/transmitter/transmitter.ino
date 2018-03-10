#include <VirtualWire.h>
String comdata="";
const int xside = A0;
const int yside = A1;
int valuex = 0;
int valuey = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("setup"); 

    vw_set_tx_pin(3);          
    vw_set_ptt_inverted(true);  
    vw_setup(4000);  
}

void loop() {
  valuex = analogRead(xside);
  valuey = analogRead(yside);
  
    if( valuex < 50 && valuey < 600 && valuey > 475){
      Serial.println("前进");
      
    const char *msg ="1";   // Message to be sent
    digitalWrite(13, true);      // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);   // Turn the LED off.
    delay(50);                 // A short gap.
    }

    
    else if( valuex < 600 && valuex > 475 && valuey < 50){
      Serial.println("右转");
      
    const char *msg ="2";   // Message to be sent
    digitalWrite(13, true);      // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);   // Turn the LED off.
    delay(50);                 // A short gap.
    }

    else if( valuex < 600 && valuex > 475 && valuey > 950){
      Serial.println("左转");
      
    const char *msg ="3";   // Message to be sent
    digitalWrite(13, true);      // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);   // Turn the LED off.
    delay(50);                 // A short gap.
    }

    else if( valuey < 600 && valuey > 475 && valuex > 950){
      Serial.println("跳起");
      
    const char *msg ="4";   // Message to be sent
    digitalWrite(13, true);      // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);   // Turn the LED off.
    delay(50);                 // A short gap.
    }

  
  delay(300);
}
