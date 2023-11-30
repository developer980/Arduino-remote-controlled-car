#include <SPI.h>
#include <RF24.h>

RF24 radio(38, 32);
const byte address[6] = "00001";

int left = 0;
int right = 0;
bool tooClose = false;

void setup() { 
  pinMode(24, OUTPUT);
  pinMode(22,INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);


  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {
  digitalWrite(24, LOW);
  digitalWrite(24, HIGH);
  digitalWrite(24, LOW);

  long duration = pulseIn(22, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.println(distance);
  
  Serial.println(tooClose);

  radio.startListening();

  if(distance < 20 && distance > 4){
    tooClose = true;
  }

  else if (distance > 30 || distance <= 4){
    if(tooClose == true)
      tooClose = false;
  }
  
  int digit = 0;
  Serial.println(tooClose);
  
  if(tooClose == false){    
    if(radio.available()){
      radio.read(&digit, sizeof(digit));
      Serial.println("Message received:");
      Serial.println(digit);
      
        if (digit == 1){    
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, 100);
        }
        else if(digit != 3){
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, 0);
        }
        
        if (digit == 2){             
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(2, 100);
        }
        else if(digit != 3){
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(2, 0);
        }

        if (digit == 3){      
          
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(2, 100);

            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, 100);
        }

        else if(digit != 1 && digit != 2){
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, 0);
          digitalWrite(2, 0);
        }
        
        else if(digit == 0){
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(2, 0);

          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, 0);
        }

      }
  }
  else if(tooClose == true && distance > 4){
    Serial.println("Too close");
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(2, 100);

    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, 100);
  }

  Serial.println(tooClose);

  delay(10);
}