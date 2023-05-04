/*
   PIR sensor tester
*/
int LDRInput = A0;
int relay = 10;         // choose the pin for the LED
int inputPin1 = 2;            // choose the input pin (for PIR sensor)
int inputPin2 = 3;            // choose the input pin (for PIR sensor)
int pirState = LOW;
// we start, assuming no motion detected
int val1 = 0;                 // variable for reading the pin status
int val2 = 0;                 // variable for reading the pin status


void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);    // declare relay as output
  pinMode(inputPin1, INPUT);  // declare sensor as input
  pinMode(inputPin2, INPUT);
  //pinMode(LDRInput, INPUT); // declare sensor as input
}

void loop() {
  int value = analogRead(LDRInput); //Reads the Value of LDR(light).
  Serial.print("LDR value is :");//Prints the value of LDR to Serial Monitor.
  Serial.println(value);


  if (value > 300) {

    val1 = digitalRead(inputPin1);  // read input value
    val2 = digitalRead(inputPin2); // read input value
    /*Serial.print("S1 value is :");
    Serial.print(val1);
    Serial.print("S1 value is :");
    Serial.print(val2);*/
    if (val1 == HIGH || val2 == HIGH) {         // check if the input is HIGH
      digitalWrite(relay, HIGH);  // turn LED ON
      Serial.println("Motion detected!");
      delay(2000);
    }
    if (val1 == LOW && val2 == LOW) {
      digitalWrite(relay, LOW); // turn LED OFF
      Serial.println("Motion ended!");
    }
  }
      //Serial.println();
  delay(200);
}
