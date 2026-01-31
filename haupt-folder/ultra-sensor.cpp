#define SENDEN 6
#define ECHO 7
#define LAUTSPRECHER 4
#define LED 8

long Zeit;
long Entferung;

void setup() {
  
  pinMode(SENDEN, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop(){
  
  digitalWrite(SENDEN, LOW);
  delayMicroseconds(2);
  digitalWrite(SENDEN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENDEN, LOW);

Zeit = pulseIn(ECHO, HIGH);
Entferung = (Zeit / 2) * 0.03432; // in cm

// display dinge lol
Serial.print("Entferung: ");
Serial.print(Entferung);
Serial.print(" cm");

if (Entferung > 0 && Entferung < 20) {
  int frequnez = map(Entferung, 1,20,1000, 200);
  tone(LAUTSPRECHER, frequnez, 200);

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
 }
  delay(100);
}