// Erstellt von mayi-oi am 12.06.2024
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <PID_v1.h>

// Create an MPU6050 object
MPU6050 mpu; //(keine anhung wie habe MPU6500 mpu?)

// PID control variables
double Setpoint, Input, Output;
double Kp = 10, Ki = 5, Kd = 1;
PID pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

//Montor-Pins
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

void loop()
{
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    double angle = atan2(ay, az) * 180 / PI;
    Input = angle;
    pid.Compute();

    int motorSpeed = (int)Output;
    if (Output > 0)
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    }
    else
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        motorSpeed = -motorSpeed;

        Serial.print("Winkel: ");
        Serial.print(angle);
        Serial.print(" Motor: ")
        Serial.println(Output);
    }
}