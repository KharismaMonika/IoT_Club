#define ECHO_PIN 2
#define TRIG_PIN 15
#define ledmerah 13
#define ledkuning 12
#define ledhijau 14
#define buzzer 26

int jarak = 0;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledmerah, OUTPUT); 
  pinMode(ledkuning, OUTPUT); 
  pinMode(ledhijau, OUTPUT); // 
  pinMode(buzzer, OUTPUT); // 

}

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  jarak = readDistanceCM();
  Serial.print("Jarak: ");
  Serial.println(jarak);

  if(jarak > 50 && jarak <= 100){
    digitalWrite(ledhijau, HIGH);
    digitalWrite(ledkuning, LOW);
    digitalWrite(ledmerah, LOW);
    noTone(buzzer); 
  }
  else if(jarak >100 && jarak <= 200){
    digitalWrite(ledhijau, HIGH);
    digitalWrite(ledkuning, HIGH);
    digitalWrite(ledmerah, LOW);
    noTone(buzzer); 
  }
  else if(jarak >200 && jarak <= 300){
    digitalWrite(ledhijau, HIGH);
    digitalWrite(ledkuning, HIGH);
    digitalWrite(ledmerah, HIGH);
    noTone(buzzer); 
  }
  else if(jarak >300){
    digitalWrite(ledhijau, HIGH);
    digitalWrite(ledkuning, HIGH);
    digitalWrite(ledmerah, HIGH);
    tone(buzzer, 1000); 
  }
  delay(100);
}
