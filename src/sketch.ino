const int trigPin = 9;
const int echoPin = 10;
const int LED1 = 4;
const int LED2 = 3;
const int LED3 = 2;
long time;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    time = pulseIn(echoPin, HIGH);
    distance = time * 0.0343 / 2;  

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm\r ");
    if (distance < 10) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    }
    else if (distance < 20 && distance > 10) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH); 
  }
  else if (distance > 20 and distance < 30) {
    digitalWrite(LED1, HIGH);
  }
  else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

  }


    delay(100);
}
