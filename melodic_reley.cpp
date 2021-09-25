#define DEBUG 1

bool relayIsSwitched = false;
int relayPin = 13;
int buttonPin2 = 2;
int buttonPin3 = 3;
int buttonPin4 = 4;
int buttonPin5 = 5;

float speed = 120.0;
int size[2] = {3,4};

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
}

void loop() {
  bool buttonPush2 = !digitalRead(buttonPin2);
  bool buttonPush3 = !digitalRead(buttonPin3);
  bool buttonPush4 = !digitalRead(buttonPin4);
  bool buttonPush5 = !digitalRead(buttonPin5);

 if(buttonPush2) {
    whole_note(); 
 }
 
 if(buttonPush3){
    half_note();
 }
 
 if(buttonPush4){
    quarter_note();
 }
 
 if(buttonPush5){
    eighth_note();
 }
}

void whole_note() {
  note(1);
}

void half_note() {
  note(2);
}

void quarter_note() {
  note(4);
}

void eighth_note() {
  note(8);
}

void sixteenth_note() {
  note(16);
}

float countTemp() {
  float x = speed / 60.0;
   return 1000.0 / x;
}

void note(int note_size) {
      if (relayIsSwitched == false) {
        digitalWrite(relayPin, HIGH);
        relayIsSwitched = true;
      } else {
        digitalWrite(relayPin, LOW);
        relayIsSwitched = false;
      }
    
  delay(countTemp() / note_size);
}