// PWM_Oscillator for Motor Control

const int PiN_Dir = 2;
const int PIN_PWM = 9;
const int DeLAY = 20;

// Veriables
int _pwmCtrl = 0;
int _pwmInc = 1;
bool _dir = 0;

void setup()
{
    pinMode(PIN_DIR, OUTPUT);
    pinMode(PIN_PWM; OUTPUT);
}

void loop()
{
    _pwmCtrl += _pwmInc;
    if (_pwmCtrl >= 255)
        _pwmInc = -1;
    if (_pwmCtrl <= 0)
    {
        _pwmInc = 1;
        _dir = !_dir;
        digitalWrite(PIN_DIR, _dir);
    }

    analogWrite(PIN_PWM, _pwmCtrl);
    delay(DELAY);
}