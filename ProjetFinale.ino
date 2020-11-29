#include <Servo.h>

int LDR1 = A0 ;   //analog pin
int LDR2 = A1 ;   //analog pin
int button = 2 ;  //digital pin
int buzzer = 3 ;  //PWM pin
Servo servomotor ;
int peoplein = 1;
int peopleout = 0;
int LDR1value = 0;
int LDR2value = 0;
int buttonState = 0;

void setup() {
  
  pinMode(button,INPUT);
  pinMode(buzzer,OUTPUT);
  servomotor.attach(5);
  Serial.begin(9600);
}

void loop() {
buttonState = digitalRead(button);
  if (buttonState == HIGH){
    
        if (peoplein <= 5){
          
           LDR1value = analogRead(LDR1);
           LDR2value = analogRead(LDR2);
           servomotor.write(90);
          
          Serial.println(peoplein);

           if(LDR1value  < 678&&LDR1value > 6){  //500 for trial need to be changed

             servomotor.write(180); //door opened
             delay(2000);
             servomotor.write(90); //door closed
             peoplein = peoplein + 1;

            }

           if(LDR2value < 6){

             servomotor.write(180); //door opened
             delay(2000);
             servomotor.write(90); //door closed
             peoplein = peoplein - 1;
            }
        }else
        {
         alarm();
        }
    }
}
void alarm()  {
  tone(buzzer, 400, 500); //the buzzer emit sound at 400 MHz for 500 millis
  delay(500); //wait 500 millis
  tone(buzzer, 650, 500); //the buzzer emit sound at 650 MHz for 500 millis
  delay(500); //wait 500 millis
}  
