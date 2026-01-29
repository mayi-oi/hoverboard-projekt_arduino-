#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <PID_v1.h>

// MPU650 mpu;

double Setpoint, Input, Output;
double Kp = 10, =5, Kd = 1;
PID pid(&Input,&Output, &Setpoint, Kp, Ki, Kd, DIRECT);

int enA = 9;
int in1 = 8;
int in2 = 7;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  Setpoint = 0;

  pid.SetMode(AUTOMATIC);
  pin.SetOutputlimts(-255, 255);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop ()
{
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMontion6(&ax, &ay, &az; &gx, &gy, &gz);
  
  double angle = atan2(ay, az) * 18ß / PI;
    Input = angle;
    pid.Compute();

    int motorSpeed = (Int)Output;
    if (Output > 0)
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      {
        else
      }

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      motorSpeed = - motorSpeed;

      // display port
      Serial.print("Winkel: ");
      Serial.print(angle);
      Serial.print("Motor: ");
      Serial.println(Output);
    }
}