int relay = 3;
int ldr = 4;
int pir = 5;
int state = LOW;
int pirVal = 0;
int ldrRead = 0;
int flag = 0;
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(relay, OUTPUT);
    pinMode(ldr, INPUT);
    pinMode(pir, INPUT);
}
void loop()
{
    // put your main code here, to run repeatedly:
    ldrRead = digitalRead(ldr);
    pirVal = digitalRead(pir);
    if (ldrRead == HIGH && pirVal == HIGH)
    {
        digitalWrite(relay, LOW);
        delay(500);
        if (state == LOW)
        {
            Serial.println("Motion detected!");
            state = HIGH;
        }
    }
    else
    {
        if (pirVal == LOW)
        {
            digitalWrite(relay, HIGH);
            delay(500);
            if (state == HIGH)
            {
                Serial.println("Motion stopped!");
                state = LOW;
            }
        }
    }
}
