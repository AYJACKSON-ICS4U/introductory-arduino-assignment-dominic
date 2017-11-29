/* SimpleToggle_PB_LED */


const byte LEDpin = 3;
const byte SWITCHpin = 2;
const byte LEDpin2 = 4;

byte LEDstate = HIGH;
byte LEDstate2 = HIGH;
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
  //second led
pinMode(LEDpin2, OUTPUT);
pinMode(SWITCHpin2, INPUT);
digitalWrite(SWITCHpin2, HIGH);
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
   LEDstate2 = !LEDstate2;
    digitalWrite(LEDpin, LEDstate);
    digitalWrite(LEDpin2, !LEDstate);
    previousMillis= currentMillis;
}
}

lastSWITCHstate = SWITCHstate;
}
