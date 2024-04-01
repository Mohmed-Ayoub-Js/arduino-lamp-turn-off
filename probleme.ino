const int led = 9;
const int b1 = 7;
const int b2 = 8;
int b1value;
int b2value;
bool ledState = false;
unsigned long previousMillis = 0;
const long interval = 800;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
}
void loop() {
  unsigned long currentMillis = millis(); 
  b1value = digitalRead(b1);
  b2value = digitalRead(b2);
  if (b2value == LOW) {
    ledState = true;
  } else if (b1value == LOW) {
    ledState = false;
  }
  if (ledState == true) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digitalWrite(led, !digitalRead(led)); 
    }
  } else {
    digitalWrite(led, LOW); 
  }
}
