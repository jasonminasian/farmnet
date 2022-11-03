#define s0 14
#define s1 12
#define s2 13
#define s3 4
#define aPin A0
//Variables
int LDR_Val; // Analog value from the LDR


void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  Serial.begin(115200);
}

void loop(){
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
LDR_Val = analogRead(aPin);
  Serial.print("Analog reading from sensor = "); 
  Serial.println(LDR_Val); // between 0 - 1024
  delay(500);
}
