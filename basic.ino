/*
 * PIR sensor tester
 */
 
int relay = 10;         // choose the pin for the LED
int inputPin1 = 2;            // choose the input pin (for PIR sensor)
int inputPin2 = 3;            // choose the input pin (for PIR sensor)
int pirState = LOW;           // we start, assuming no motion detected
int val1 = 0;                 // variable for reading the pin status
int val2 = 0;                 // variable for reading the pin status


void setup() {
  pinMode(relay, OUTPUT);    // declare relay as output
  pinMode(inputPin1, INPUT);  // declare sensor as input
  pinMode(inputPin2, INPUT);  // declare sensor as input

  Serial.begin(9600);
}
 
void loop(){
  val1 = digitalRead(inputPin1);  // read input value
  val2 = digitalRead(inputPin2); // read input value
  if (val1 == HIGH || val2 == HIGH) {         // check if the input is HIGH
  digitalWrite(relay, HIGH);  // turn LED ON
  
    Serial.println("Motion detected!");
        delay(1000);
    //}
  } 
  if (val1 == LOW && val2 == LOW) {
  digitalWrite(relay, LOW); // turn LED OFF
    Serial.println("Motion ended!");
    //pirState = LOW;
  }
  }