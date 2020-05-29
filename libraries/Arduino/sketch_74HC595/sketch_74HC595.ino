/*
PIN_2 >> DATA PIN
PIN_4 >>  CLK_PIN
PIN_5 >>  LATCH_PIN  
*/

int latch_PIN = 8;
int CLK_PIN = 12;
int data_PIN = 11;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  // set pin configuratins
  pinMode(latch_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  pinMode(data_PIN, OUTPUT);
}

void loop() {
  

  // 2. genertating 8 bit data for the 8-bit shift register from (0 - 255) using a for loop
  // additionally for every CLK signal going HIGH, the DS serial data will activate the corresponding pins from Q0 to Q7
  for(int i = 0; i < 256; i++){ // here 8-bit data will be sent from (0 - 255) which will control 8 pins from Q0 to Q7 at every iteration of for loop
   //Serial.println(i, BIN);
    // 1. first the latch pin should be pulled to low for the data to be recieved by the DS pin of L4HC shift register
    digitalWrite(latch_PIN, LOW);   // now the data will be accepted

    shiftOut(data_PIN, CLK_PIN, MSBFIRST, i);   // here the value of CLK_PIN is same as data_PIN which is i

    digitalWrite(latch_PIN, HIGH);              // Disabling the latch to lock the stored data

    delay(1000);                                // display the data for 1 sec
    }
}
