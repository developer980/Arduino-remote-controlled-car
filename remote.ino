#include<SPI.h>
#include<RF24.h>

RF24 radio(2, 7);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);

  
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(6, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  int left = digitalRead(8);
  int right = digitalRead(9);
  int forward = digitalRead(6);
  

  if(left == HIGH && right == LOW){
    const int digit = 1;
    Serial.println(digit);
    radio.write(&digit, sizeof(digit));
  }

  if(right == HIGH && left == LOW){
    const int digit = 2;
    Serial.println(digit);
    radio.write(&digit, sizeof(digit));
  }

  if(left == HIGH && right == HIGH){
    const int digit = 3;
    Serial.println(digit);
    radio.write(&digit, sizeof(digit));
  }

  if(left == LOW && right == LOW){
    const int digit = 0;
    Serial.println(digit);
    radio.write(&digit, sizeof(digit));
  }
}
