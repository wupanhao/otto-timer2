#include <VirtualWire.h>

#include "Otto2.h"
Otto2 otto2;

  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]

  
void setup(){
  otto2.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
  otto2.home();
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
  
  }

void loop(){
  
  }
