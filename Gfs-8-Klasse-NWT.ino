
#define TASTE1 2
#define TASTE2 3
#define DREHDINGS A0
#define ECHO 7
#define TRIGGER 6
#define LED_LENKUNG 13
#define PWM 11
#define MOTOR1 10
#define MOTOR2 9


void setup() {
  // put your setup code here, to run once:
  pinMode(TASTE1, INPUT_PULLUP);
  pinMode(TASTE2, INPUT_PULLUP);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_LENKUNG, OUTPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(PWM, OUTPUT);
  Serial.begin(115200);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int Taste1 = digitalRead(TASTE1);
  int Taste2 = digitalRead(TASTE2);
  Serial.print("Taste1: ");
  Serial.print(Taste1);
  Serial.print(" / Taste2: ");
  Serial.print(Taste2); 
  
  // Abstands Messung
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  long dauer = pulseIn(ECHO, HIGH);
  long entfernung = (dauer/2) * 0.03432; 
  if (entfernung  <= 16)
  {
    digitalWrite(LED_LENKUNG, HIGH);
  }
  else 
  {
    digitalWrite(LED_LENKUNG, LOW);
  }
  Serial.print(" / Entfernung: ");
  Serial.print(entfernung);
  Serial.print(" cm");

  int Drehdings = analogRead(DREHDINGS);
  Serial.print(" / Drehdings: ");
  Serial.println(Drehdings);
  analogWrite(PWM, Drehdings/4);
  if (Taste1 == LOW)
  {  
    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, LOW);
  }    
  else if (Taste2 == LOW)
  {
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, HIGH);
  }
  else
  {
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, LOW);
  }
  
  
  delay(500);
}
