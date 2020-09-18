int powerPin = 10;
int groundPin = 9;
int inputPin = 2;
int value = 0;
int pirState = LOW;
int wiperPower = 3;
int wiperPark = 4;
int calibrationTime = 30;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  //initialize digital pin 10 as output and Set to HIGH so it is 5v vcc
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);

  //initialize digial pin 9 as output and set to low to be ground
  pinMode(groundPin, OUTPUT);     
  digitalWrite(groundPin, LOW);

  //set pin 2 to be input
  pinMode(inputPin, INPUT);

  //initialize wiper power output
  pinMode(wiperPower, OUTPUT);
  digitalWrite(wiperPower, HIGH);

  //initialize wiper park output
  pinMode(wiperPark, OUTPUT);
  digitalWrite(wiperPark, HIGH);

  //Allow PIR to calibrate
  for(int i = 0; i < calibrationTime; i++){
    delay(1000);
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  value = digitalRead(inputPin);       // read input value
  if (value == HIGH) {                 // check if the input is HIGH
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(wiperPower, LOW);    //Turn on wiper power
    delay(8000);                        // Leave wiper on for seconds
    digitalWrite(wiperPower, HIGH);
    delay(500);
    // park wiper in else or here??
    digitalWrite(wiperPark, LOW);
    delay(3000);
    digitalWrite(wiperPark, HIGH);      // Park Wiper
   /* if (pirState == LOW) {
      // We only want to print on the output change, not state
      pirState = HIGH;
    }*/
  }else{
    digitalWrite(LED_BUILTIN, LOW); // turn LED OFF
    digitalWrite(wiperPark, HIGH);
    digitalWrite(wiperPower, HIGH);
    delay(300);
 /*   if (pirState == HIGH){
      // we have just turned of
      // We only want to print on the output change, not state
      pirState = LOW;
    }*/
  }

}
