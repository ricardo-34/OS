int ledPin = 13;
int motorPin = 12;
float temp;
int sensorValue;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("### Temperatura monitor ###");
}

void loop()
{
  sensorValue = analogRead(A0);
  Serial.print("sensor value: ");    
  Serial.println(sensorValue);

  temp = sensorValue * (5.0 / 1023.0) * 100;
  Serial.print("Temperatura: ");
  Serial.println(temp);  

  if (temp < 5.0) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else if (temp >= 6.0 && temp <= 25.0) {
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
  }
  else if (temp > 25.0) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
  }

  delay(2000);
}