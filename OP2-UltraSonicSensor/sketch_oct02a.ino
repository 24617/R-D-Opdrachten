#define trigPin 10
#define echoPin 13

int ledRed = 5;
int ledYellow = 6;
int ledGreen = 7;

float duration, distance;

void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(ledRed, OUTPUT);
   pinMode(ledYellow, OUTPUT);
   pinMode(ledGreen, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) * 0.0343;

  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    if (distance <= 75 && distance >= 65) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, LOW);
    }
    if (distance <= 45 && distance >= 35) {
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
    } 
    if (distance <= 25 && distance >= 15) {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
    }
  }
}
