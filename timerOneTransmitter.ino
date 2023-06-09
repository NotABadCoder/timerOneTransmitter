#include <TimerOne.h>
const int outputPin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);
  
  // Set up TimerOne to generate interrupts
  Timer1.initialize();
  Timer1.attachInterrupt(Toggle);
  
  // Start with a low pulse
  digitalWrite(outputPin, LOW);
  randomSeed(analogRead(A0));
  // Start the timer
  //Timer1.start();

}
bool low=false;

void loop() {
  // put your main code here, to run repeatedly:
  
  

}
int cnt=0;
int data=3303;
bool checkReset=false;
int i=11;
void Toggle(){
  if(low){
    Timer1.setPeriod(1000);
    digitalWrite(outputPin,LOW);
    low=false;
  }
  else{
    if(checkReset==false){
      checkReset=true;
      Timer1.setPeriod(5000);
      digitalWrite(outputPin, HIGH);
      low=true;

    }
    else{
      if(i==-1){
        i=11;
        cnt++;

        if(cnt==2){
          checkReset=false;
          cnt=0;
        }
        
      }
      if(checkReset){
        int setBit=(1<<i)&data;
        if(setBit){
          Timer1.setPeriod(3000);
          digitalWrite(outputPin, HIGH);

        }
        else{
          Timer1.setPeriod(1000);
          digitalWrite(outputPin, HIGH);
        }
        i--;
        low=true;
      }
    }
  }
}