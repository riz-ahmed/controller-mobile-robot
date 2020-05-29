int BuzzerPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(BuzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long BuzzerFreq = 100;

  for(int i = 0; i<10; i++){
      tone(BuzzerPin, BuzzerFreq);
      delay(1000);                    // tone at this freq for 1s
      BuzzerFreq = BuzzerFreq + 100;  // incease 100 Hz
      noTone(BuzzerPin);              // pause for 1s
      delay(1000);       
    }
}
