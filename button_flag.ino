const int ledPin = 9;
const int buttonPin= 13;
int flag = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
}
void loop() {
  int bt = digitalRead(buttonPin);
  if(bt == LOW){
    if(flag == 0){
      for(int i=0;i<=255;i++){
        analogWrite(ledPin,i);
        delay(4);
      }
      flag = 1;
    }
  }
  else {
    flag = 0;
    analogWrite(ledPin,0);
  }
}
