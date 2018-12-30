String voice;
int delayFwdBck = 5000;
int delayTurns = 2000;
bool printDebug = true;

void setup() {
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
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
        if (SubStringFunc(voice,"stop")){
            stop();
          }
        else if (SubStringFunc(voice,"forward")){
            forward();
          }
        else if (SubStringFunc(voice,"left")){
            left();
          }
        else if (SubStringFunc(voice,"right")){
            right();
          }
        else if (SubStringFunc(voice,"reverse")){
            reverse();
          }
        else if (SubStringFunc(voice,"clockwise") && !SubStringFunc(voice,"anti")){
            Sharpright();
          }
        else if (SubStringFunc(voice,"clockwise") && SubStringFunc(voice,"anti")){
            Sharpleft();
          }
  }
  voice="";    //Re-Initialize voice for new input

}

bool SubStringFunc(String str,String substr){
    if(str.indexOf(substr) != -1){
        return true;
     }else {
        return false;   
     }
}

//Stop Function
void stop(){
    if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("stop");
      }
    }  
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11 , LOW);
}

//Forward Function
void forward(){

//for Debugging
  if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("forward");
      }
    }
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);    
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    //Add Some Delay

    delay(delayFwdBck);
    stop();
}

//left Function
void left(){

    if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("left");
      }
    }
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);    
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);

    delay(delayTurns);
    stop();
}

//right Function
void right(){

    if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("right");
       }
    }
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);    
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    
    delay(delayTurns);
    stop();
}

//Sharp Left Function
void Sharpleft(){
    if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("Sharpleft");
      }
    }    
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);    
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);    
    
    delay(delayTurns);
    stop();
}

//Sharp Right Function
void Sharpright(){
    if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("Sharpright");
      }
    }   
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);    
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    
    delay(delayTurns);
    stop();
}

//Reverse Function
void reverse(){
    if(printDebug){
      for (int i=0; i<100;i++){
        Serial.println("reverse");
      }
    }  
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);    
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
   
    delay(delayFwdBck);
    stop();
}
