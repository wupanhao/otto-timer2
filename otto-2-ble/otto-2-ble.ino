#include "Otto2.h"
Otto2 otto2;



#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]


void setup(){
  Serial.begin(9600);
  BTserial.begin(9600);
  otto2.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
  otto2.home();
  /*
  otto2.walk();
  otto2.jump();
  otto2.turn();
  otto2.bend();
  otto2.shakeLeg();
  otto2.updown();
  otto2.swing();
  otto2.tiptoeSwing();
  otto2.jitter();
  otto2.ascendingTurn();
  otto2.moonwalker();
  otto2.crusaito();
  otto2.flapping();
  otto2.home();
    */
  }

// TEMPO: 121 BPM
int t=495;
double pause=0;
char data;
void loop()
{
   if(BTserial.available() > 0)  // Send data only when you receive data:
  {
    data = BTserial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line 
    if(data == '0')            //Checks whether value of data is equal to 1 
   {
      otto2.home();
   }  
    else if(data == '1')       //Checks whether value of data is equal to 0
    {
      otto2.walk();
    }
    else if(data == '2')       //Checks whether value of data is equal to 0
    {
      otto2.turn();
    }    
    else if(data == '3')       //Checks whether value of data is equal to 0
    {
      otto2.turn(4,2000,RIGHT);
    }
    else if(data == '4')       //Checks whether value of data is equal to 0
    {
      otto2.bend();

    }
      else if(data == '5')       //Checks whether value of data is equal to 0
    {
      otto2.shakeLeg();

    }
      else if(data == '6')       //Checks whether value of data is equal to 0
    {
      otto2.updown();

    }
    else if(data == '7')       //Checks whether value of data is equal to 0
    {
      otto2.swing();

    }
    else if(data == '8')       //Checks whether value of data is equal to 0
    {
      otto2.tiptoeSwing();

    }
    else if(data == '9'){
      otto2.jitter();
     
    }
    else if(data == 'a'){
      otto2.ascendingTurn();
   
    }    
    else if(data == 'b'){
      otto2.moonwalker();
    
    }
    else if(data == 'c'){
      otto2.crusaito();
      
    }
    else if(data == 'd'){
       otto2.flapping();           
    }
    else if(data == 'e'){
      otto2.jump();      
    }      
  } 
 
}

