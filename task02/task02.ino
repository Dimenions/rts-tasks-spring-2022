//Вариант 400 мс 150 мс  100 мс  250 мкс 35 мкс

#include <TaskManagerIO.h>

bool pin5State = false;
bool pin6State = false;
bool pin9State = false;
bool pin10State = false;
bool pin11State = false;


void checkState2() {
    digitalWrite(2, pin2State);
    pin2State = !pin2State;           
}

void checkState3() {
    digitalWrite(3, pin3State);
    pin3State = !pin3State;           
}

void checkState4() {
    digitalWrite(4, pin4State);
    pin4State = !pin4State;           
}

void checkState5() {
    digitalWrite(5, pin5State);
    pin5State = !pin5State;           
}

void checkState6() {
    digitalWrite(6, pin6State);
    pin6State = !pin6State;           
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  taskManager.scheduleFixedRate(400000, checkState2, TIME_MICROS);
  taskManager.scheduleFixedRate(150000, checkState3, TIME_MICROS);
  taskManager.scheduleFixedRate(100000, checkState4, TIME_MICROS);
  taskManager.scheduleFixedRate(250, checkState5, TIME_MICROS);
  taskManager.scheduleFixedRate(35, checkState6, TIME_MICROS);

}

void loop() {
  taskManager.runLoop();
}
