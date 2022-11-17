

#define IN_PIN     5
#define LED        3
#define ANALOG_IN  A0

#define MOTOR_PWM 11
#define MOTOR_A1  10
#define MOTOR_A2   9


#define ECHO     8
#define TRIGGER  7


void setup() {
  // put your setup code here, to run once:

  // Serielle Schnittstelle
  Serial.begin(115200);

  // LED und Potentiometer
  pinMode(LED, OUTPUT);
  pinMode(IN_PIN, INPUT_PULLUP);

// Ultraschall Sensor
  pinMode(TRIGGER, OUTPUT);   // TrigPin als OUTPUT
  pinMode(ECHO, INPUT);       // EchoPin als INPUT

  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
}

int Geschwindigkeit = 0;
int Abstand = 0;

void loop() {

  int analogIn;
  int Zustand;

  // Analog Eingang lesen und an LED als pulweite ausgeben (Helligkeit)
  analogIn = analogRead(ANALOG_IN);
  Geschwindigkeit = analogIn / 4;   // Geteilt durch 4, da Analog in: 0...1023, --> PWM 0...255
  //digitalWrite(LED, Zustand);
  analogWrite(LED, Geschwindigkeit);
  Serial.print("Geschwindigkeit: ");
  Serial.print(Geschwindigkeit);

  // Abstands Messung
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  // EchoPin, gibt die Zeit in us an, die der Schall benötigt hat um hin und zurück zukommen
  int schallDauer = pulseIn(ECHO, HIGH);
  // Calculating the distance
  Abstand = schallDauer * 0.034 / 2; // Schallgeschwindigkeit geteilt durch zwei (hin und zurück)
  // Displays the distance on the Serial Monitor
  Serial.print(" / Abstand: ");
  Serial.print(Abstand);
  Serial.print(" cm");

  
  // Taster einlesen (wenn LOW, Taster gedrückt, motor bewegen)
  Zustand = digitalRead(IN_PIN);
  if (Zustand == LOW) {
    analogWrite(MOTOR_PWM, Geschwindigkeit);
    digitalWrite(MOTOR_A1, HIGH);
    digitalWrite(MOTOR_A2, LOW);
  }
  else {
    analogWrite(MOTOR_PWM, 0);
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, LOW);
  }

  Serial.print(" / Zustand: ");
  Serial.print(Zustand);
  Serial.print("");

  Serial.println("");
  

  delay(500);
  // put your main code here, to run repeatedly:
  //digitalWrite(3, HIGH);
  //delay(300);
  //digitalWrite(3, LOW);
  //delay(700);
}
