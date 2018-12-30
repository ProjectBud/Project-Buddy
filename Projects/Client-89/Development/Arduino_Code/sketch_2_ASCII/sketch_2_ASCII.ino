String voice;

void setup() {
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  //Serial.println("Entered Loop");

while (Serial.available()){
  delay(10);
  char c = Serial.read();
  if (c == '#') {break;}
  voice = voice + c;
  
}
  Serial.println(voice);

  if (voice.length() > 0){
    if (voice == "hello"){
        helloFunc();
      }
  }
  voice="";

}

void helloFunc(){
for (int i=0; i<100;i++){
    Serial.println("hello");
    }
}
