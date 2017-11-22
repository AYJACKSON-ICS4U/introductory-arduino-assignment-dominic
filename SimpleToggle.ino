 /* SimpleToggle_PB_LED */


const byte LEDpin = 3;
const byte SWITCHpin = 2;

byte LEDstate = HIGH;
byte SWITCHstate;
byte lastSWITCHstate;

long previousMillis= 0;
long currentMillis= 0;
long interval= 200;

void setup() {
  // put your setup code here, to run once:
pinMode(LEDpin, OUTPUT);
pinMode(SWITCHpin, INPUT);
digitalWrite(SWITCHpin, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  
SWITCHstate = digitalRead(SWITCHpin);
Serial.print(currentMillis);
currentMillis=millis();
if (currentMillis-previousMillis>interval)
{

if ((lastSWITCHstate == HIGH) && (SWITCHstate == LOW))
{
    LEDstate = !LEDstate;
    digitalWrite(LEDpin, LEDstate);
    previousMillis= currentMillis;
}
}

lastSWITCHstate = SWITCHstate;
}
