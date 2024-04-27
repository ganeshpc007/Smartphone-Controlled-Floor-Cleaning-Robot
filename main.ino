char bt_signal;
const int in1 = 2;
const int in2 = 4;
const int in3 = 5;
const int in4 = 7;

int pump = 8;

#define en1 3
#define en2 6

int M1_Speed = 255; // speed of motor 1
int M2_Speed = 252; // speed of motor 2

void setup()
{
    Serial.begin(9600);
    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    pinMode(pump, OUTPUT);
    digitalWrite(pump, LOW);
}

void loop()
{
    if (Serial.available())
    {
        bt_signal = Serial.read();
        Serial.println(bt_signal);
    }

    // forward
    if (bt_signal == 'F')
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

        analogWrite(en1, M1_Speed);
        analogWrite(en2, M2_Speed);
    }

    // Reverse
    if (bt_signal == 'B')
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        analogWrite(en1, M1_Speed);
        analogWrite(en2, M2_Speed);
    }

    //  Right Turn
    else if (bt_signal == 'R')
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

        analogWrite(en1, M1_Speed);
        analogWrite(en2, M2_Speed);
    }

    // Left Turn
    else if (bt_signal == 'L')
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

        analogWrite(en1, M1_Speed);
        analogWrite(en2, M2_Speed);
    }

    else if (bt_signal == 'S')
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
    }
    delay(100);

    if (bt_signal == 'P')
    {
        digitalWrite(pump, HIGH);
    }

    else if (bt_signal == 'p')
    {
        digitalWrite(pump, LOW);
    }
}