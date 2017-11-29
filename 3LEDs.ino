/* SimpleToggle_PB_LED */


const byte LEDpin = 3;
const byte SWITCHpin = 2;
const byte LEDpin2 = 4;
const byte LEDpin3 = 5;

byte LEDstate = HIGH;
byte LEDstate2 = HIGH;
byte LEDstate3 = HIGH;

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
pinMode(SWITCHpin, INPUT);
digitalWrite(SWITCHpin, HIGH);
  //Third led
pinMode(LEDpin3, OUTPUT);
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
    if (LEDstate == HIGH) {
    LEDstate = !LEDstate;
    LEDstate2 = !LEDstate2;
    }
    else if (LEDstate2 == HIGH) {
      LEDstate2 = !LEDstate2;
      LEDstate3 = !LEDstate3;
    }
    else {
    LEDstate3 = !LEDstate3;
      LEDstate = !LEDstate;
    }
    digitalWrite(LEDpin, LEDstate);
    digitalWrite(LEDpin2, LEDstate2);
    digitalWrite(LEDpin3, LEDstate3);
    previousMillis= currentMillis;
}
}

lastSWITCHstate = SWITCHstate;
}
