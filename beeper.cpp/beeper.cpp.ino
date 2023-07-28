#define DEBUG 1

int inPin2 = 2;
int inPin3 = 3;
int outPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(inPin2, INPUT_PULLUP);
  pinMode(inPin3, INPUT_PULLUP);
  pinMode(outPin, OUTPUT);
}

void loop() {
  if(digitalRead(inPin2)) {
    digitalWrite(outPin, HIGH);
  }
  
  if(digitalRead(inPin3)) {
    digitalWrite(outPin, LOW);
  }
}
