int relay_pins[] = {6,7,8,9,10,11,5};
int SIZE = 7;
char out;

int getBit(int pos) {
  return (out >> pos) & 1; 
}

void setup(){
  Serial.begin(9600);
  Serial.flush();
  out = 0;
  for(int i = 0;i<SIZE;i++){
    pinMode(relay_pins[i],OUTPUT);
    digitalWrite(relay_pins[i],HIGH);
  }
}

void loop() {   
  if (Serial.available() >= 1) {
    out = Serial.read();
    Serial.println(out,DEC);
    for(int i = SIZE;i>=0;i--){
        if(getBit(i) == 1){
            digitalWrite(relay_pins[i],LOW);
        }else{
            digitalWrite(relay_pins[i],HIGH);
        }
    } 
    out =0;
  }
  delay(125);
  Serial.flush();
}