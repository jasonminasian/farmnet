#define s0 14
#define s1 12
#define s2 13
#define s3 4
#define aPin A0
//Variables
String str;
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

}

String channel() {
  
if (str[0] = 0 ) {
  digitalWrite(s0, LOW);
}  else digitalWrite(s0, HIGH);
  Serial.println str[0];
}

if (str[1] = 0 ) {
  digitalWrite(s1, LOW);
} else digitalWrite(s1, HIGH);
  Serial.println str[1];
}
if (str[2] = 0 ) {
  digitalWrite(s2, LOW);
} else digitalWrite(s2, HIGH);
  Serial.println str[2];
}

if (str[3] = 0 ) {
  digitalWrite(s3, LOW);
} else digitalWrite(s3, HIGH);
  Serial.println str[3];
}
}
