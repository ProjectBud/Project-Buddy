int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);



  //Serial.begin(38400);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  

   /*if(Serial.available() > 0){ // Checks whether data is comming from the serial port
      state = Serial.read(); // Reads the data from the serial port
   }
   if (state == '0') {
    digitalWrite(LED_BUILTIN, LOW); // Turn LED OFF
    Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
    state = 0;
   }
   else if (state == '1') {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED: ON");;
    state = 0;
   } */
}


void forward(){
    digitalWrite(5, HIGH);
    digitalWrite(11, HIGH);
    //digitalWrite(10, LOW);
   //digitalWrite(4, LOW);

    
    digitalWrite(LED_BUILTIN, HIGH);
}
