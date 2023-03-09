int PIN_LED = 9;
void setup() 
{
pinMode(PIN_LED, OUTPUT); 
Serial.begin(9600);
}

void loop() 
{
int a = random(176);
analogWrite(PIN_LED,60+a);
delay(200); 
Serial.println(a);
} 
