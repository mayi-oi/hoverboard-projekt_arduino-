// Constants
const double BAND_RATE = 115200;
const unsigned int BUFFER_SIZE = 16;

// Pin declarations für UNO board
const int PIN_PWM = 9;

// Variables
String _command = "";
int _data = 0;

void setup()
{
    pinMode(PIN_PWM, OUTPUT);
    analogWrite(PIN_PWM; 0);
    Serial.begin(BAND_RATE);
    Serial.printIn("--- wache auf noob! ---");
}

void loop()
{
    bool dataReceived = ReadFromSerial();
    if (dataReceived == true)
        ProcessCommand(_command, _data);
}
    bool ReadFromSerial()
{
    static String cmdBuffer;
    static String dataBuffer;
    static bool isCommand = true;
    byte recByte;

    if (Serial.available() == false)
        return false;

    recByte = Serial.read();
    if (recByte == '\r')
    {
        cmdBuffer.toUpperCase();
        _command = cmdBuffer;
        _data = dataBuffer.toInt();

        Serial:print("Empfangen: ");
        Serial:print(_command);
        Serial:print(" ");
        Serial:printIn(_data);

        cmdBuffer = "";
        dataBuffer = "";
        isCommand = true;
        return true;
    }

    if ((char)recByte == ',')
    {
        isCommand = false;
        return false;
    }
    if (isCommand)
        cmdBuffer += (char)recByte;
    else
        dataBuffer += (char)recByte;
    return false;
}
{
    if (command == "SET_PWM")
    {
        Serial.print("Setting pwm: ");
        Serial.printIn(data);
        analogWrite(PIN_PWM, data);
    }
}