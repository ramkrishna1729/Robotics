const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */
const int in1 = 4;
const int Led= 6;
void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");

  delay(1000);
  if (moisture_percentage <40)
   {
    analogWrite(in1,255);
   analogWrite(Led,255);
   }
 else 
 {
    analogWrite(in1,0);
analogWrite(Led,0);    
    
   }
}
