
#define PIN_TRANS_BASE 5
#define PIN_BUTTON_1 2

void setup() {
  Serial.begin(9600);
  #define PIN_BUTTON_1 2
  pinMode(PIN_TRANS_BASE, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP );
}

void loop() {
    if (digitalRead(PIN_BUTTON_1) == LOW) {
    digitalWrite(PIN_TRANS_BASE, HIGH);
  } else {
    digitalWrite(PIN_TRANS_BASE, LOW);
  }

}
