#include <VirtualWire.h>

#include "Otto2p.h"
Otto2 otto2;

  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]

void wave_hands(){
  Oscillator hands[2];
  hands[0].attach(6); 
  hands[1].attach(7); 

  hands[0].SetPosition(45);
  delay(1000);
  hands[0].SetPosition(135);
  delay(1000);
  hands[0].SetPosition(45);
  delay(1000);
  hands[0].SetPosition(135);
  delay(1000);
  hands[0].SetPosition(90);
  hands[1].SetPosition(90);
  delay(1000);
  hands[0].detach();
  hands[1].detach();
}
  
void setup(){
  otto2.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
  wave_hands();
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
  wave_hands();
  }

void loop(){
  
  }
