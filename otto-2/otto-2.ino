

#include "Otto2.h"
Otto2 otto2;

  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]

const int TrigPin = 10;
const int EchoPin = 9;
float distance;
void init_sr()
{   // 初始化串口通信及连接SR04的引脚
        Serial.begin(9600);
        pinMode(TrigPin, OUTPUT);
    // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
        pinMode(EchoPin, INPUT);
    Serial.println("Ultrasonic sensor:");
}
void dance(){

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

void get_dist()
{
    // 产生一个10us的高脉冲去触发TrigPin
        digitalWrite(TrigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(TrigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(TrigPin, LOW);
    // 检测脉冲宽度，并计算出距离
        distance = pulseIn(EchoPin, HIGH) / 58.00;
        Serial.print(distance);
        Serial.print("cm");
        Serial.println();
        if(distance<5){
          dance();
        }
        delay(1000);
}



void setup(){
  otto2.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
  otto2.home();
  init_sr();
  }

void loop(){
  get_dist();
  }
