#define PIN_BUTTON_1 1
#define PIN_BUTTON_2 2
#define PIN_PUMP_WATERING 3
#define PIN_PUMP_DRAIN 4
#define PIN_BUZZER 5 

#define TIME_INTERVAL_WATERING 14400000 // 4 hour  
#define TIME_INTERVAL_DRAIN 21600000 //6 hour  
#define TIME_PUMP_WORKING 40000 // 40 sec 

int buttonState = 0;
int is_pump_working_now = 0;
uint32_t myTimer1, myTimer2, myTimer3;
// В этой функции определяем первоначальные установки
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP ); 
  pinMode(PIN_BUTTON_2, INPUT_PULLUP ); 
  pinMode(PIN_PUMP_WATERING, OUTPUT);
  pinMode(PIN_PUMP_DRAIN, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop()
{
  if (digitalRead(PIN_BUTTON_1) == LOW) {
    pump_watering();
  }
  
  if (digitalRead(PIN_BUTTON_2) == LOW) {
    pump_drain();
  }

  if (millis() - myTimer1 >= TIME_INTERVAL_WATERING) {        
    pump_watering(); 
  }

  if (millis() - myTimer2 >= TIME_INTERVAL_DRAIN) {               
     pump_drain();
  }
}


void pump_watering() {
  if(is_pump_working_now == 1) {
    return;
  }

  Serial.println("pump_watering begin");
  digitalWrite(PIN_PUMP_WATERING, HIGH);
  tone(PIN_BUZZER, 1000,TIME_PUMP_WORKING);
  is_pump_working_now = 1;
  delay(TIME_PUMP_WORKING);
  digitalWrite(PIN_PUMP_WATERING, LOW); 
  Serial.println("pump_watering end");
  is_pump_working_now = 0;
  myTimer1 = millis();
}

void pump_drain() {
  if(is_pump_working_now == 1) {
    return;
  }

  Serial.println("pump_drain begin");
  digitalWrite(PIN_PUMP_DRAIN, HIGH);
  tone(PIN_BUZZER, 500, TIME_PUMP_WORKING);
  is_pump_working_now = 1;
  delay(TIME_PUMP_WORKING);
  digitalWrite(PIN_PUMP_DRAIN, LOW); 
  Serial.println("pump_drain end");
  is_pump_working_now = 0;
  myTimer2 = millis();
}