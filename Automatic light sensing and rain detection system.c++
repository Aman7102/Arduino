#define LIGHT_SENSOR_PIN 2
#define RELAY_PIN 3
#define RAIN_SENSOR_PIN A0
#define BUZZER_PIN 5

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int lightValue = digitalRead(LIGHT_SENSOR_PIN);

  if (lightValue == HIGH)
  {
    digitalWrite(RELAY_PIN, LOW);
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);
  }

  int rainValue = analogRead(RAIN_SENSOR_PIN);
  Serial.println(rainValue);

  if (rainValue < 1000)
  {
    analogWrite(BUZZER_PIN, 50);
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);
  }

  delay(1000);
}