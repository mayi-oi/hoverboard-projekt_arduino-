#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <PID_v1.h>

MPU6050 mpu;  // Instanz des MPU6050-Sensors

// PID-Variablen
double Setpoint, Input, Output;
double Kp = 10, Ki = 5, Kd = 1;  // Ki war falsch deklariert
PID pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// Motor-Pins
int enA = 9;
int in1 = 8;
int in2 = 7;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  Setpoint = 0;  // Zielwinkel (z. B. 0° für Balance)

  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-255, 255); 

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // Sensorwerte lesen
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  // Korrigiert: "getMotion6" statt "getMontion6"

  // Winkel berechnen (in Grad)
  double angle = atan2(ay, az) * 180.0 / PI;  // Korrigiert: "180" statt "18ß"
  Input = angle;

  // PID-Regler berechnen
  pid.Compute();

  // Motorsteuerung
  int motorSpeed = abs((int)Output);  // Betrag für analogWrite
  if (Output > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  analogWrite(enA, motorSpeed);  // Motorgeschwindigkeit setzen

  // Debugging-Ausgabe
  Serial.print("Winkel: ");
  Serial.print(angle);
  Serial.print("  Motor: ");
  Serial.println(Output);
}
