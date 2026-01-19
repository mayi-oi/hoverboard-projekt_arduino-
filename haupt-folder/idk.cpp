#define SENDEN 6
#define ECHO 7
#define LAUTSPRECHER 4

long Zeit;
long Entferung;

void setup()
{
pinMode(SENDEN, OUTPUT);
pinMode(ECHO, INPUT);
}

void loop()
{
digitalWrite(SENDEN, LOW);
delay(10);

digitalWrite(SENDEN, HIGH);
delayMicroseconds(10);
digitalWrite(SENDEN, LOW);
Zeit = pulseIn(ECHO, HIGH);
Entferung = (Zeit / 2) * 0.03432;
if (Entferung < 20)
{
  delay(500);
  tone(LAUTSPRECHER, map(Entferung,1 ,20, 200, 1000), 500);
}
}