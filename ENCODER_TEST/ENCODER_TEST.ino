int vitri = 0;
void chay(){
  if(digitalRead(4)==1){
    vitri++;
  }
}
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,chay,RISING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  chay();
  Serial.println(vitri);
}
