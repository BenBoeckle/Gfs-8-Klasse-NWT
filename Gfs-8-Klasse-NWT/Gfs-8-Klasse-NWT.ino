
#define TASTE_START_AUTOMATISCH 9



//Abstandssensor
#define ECHO 11
#define TRIGGER 10
#define OUTPUT_ABSTAND 8

#define PWM_RICHTUNG 3
#define MOTOR_RICHTUNG1 7
#define MOTOR_RICHTUNG2 6

#define PWM_LENKUNG 4
#define MOTOR_LENKUNG1 2
#define MOTOR_LENKUNG2 5



void setup() 
{
  // put your setup code here, to run once:
  pinMode(TASTE_START_AUTOMATISCH, INPUT_PULLUP);
  
  // Abstandssensor
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(OUTPUT_ABSTAND, OUTPUT);

  // Motor vorwärts/rückwärts
  pinMode(PWM_RICHTUNG, OUTPUT);
  pinMode(MOTOR_RICHTUNG1, OUTPUT);
  pinMode(MOTOR_RICHTUNG2, OUTPUT);

  // Motor rechts/links
  pinMode(PWM_LENKUNG, OUTPUT);
  pinMode(MOTOR_LENKUNG1, OUTPUT);
  pinMode(MOTOR_LENKUNG2, OUTPUT);
  
  Serial.begin(115200); 
}

void loop() 
{
  unsigned long StopLenkungZeit = 0;
  // put your main code here, to run repeatedly:
  int Taste1 = digitalRead(TASTE_START_AUTOMATISCH);
 
  // Warte bis Start gedrückt wird
  while (Taste1 == HIGH )
  {
  }
  delay(1000);

  digitalWrite(OUTPUT_ABSTAND, LOW);

  // Lenkung auf 0
  analogWrite(PWM_LENKUNG, 0);
  digitalWrite(MOTOR_LENKUNG1, LOW);
  digitalWrite(MOTOR_LENKUNG2, LOW);


  int Geschwindigkeit = 200; //analogRead(GESCHWINDIGKEIT) / 4;
  analogWrite(PWM_RICHTUNG, Geschwindigkeit);
  digitalWrite(MOTOR_RICHTUNG1, HIGH);
  digitalWrite(MOTOR_RICHTUNG2, LOW);

  delay(1000);
  analogWrite(PWM_RICHTUNG, Geschwindigkeit * 0.8);


  // Solange Taste nicht gedrückt wird
  while (Taste1 == HIGH)
  {
    // Abstands Messung
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(2);  
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    long dauer = pulseIn(ECHO, HIGH);
    long entfernung = (dauer/2) * 0.03432; 
    if (entfernung  < 10)
    {
      digitalWrite(OUTPUT_ABSTAND, HIGH);

      // Zu nahe am Hindernis, anhalten
      analogWrite(PWM_RICHTUNG, 0);
      digitalWrite(MOTOR_RICHTUNG1, LOW);
      digitalWrite(MOTOR_RICHTUNG2, LOW);
    }
    else if (entfernung  < 70)
    {
      digitalWrite(OUTPUT_ABSTAND, HIGH);
      analogWrite(PWM_RICHTUNG, Geschwindigkeit * 0.85);

      // Starte mit Lenkung
      analogWrite(PWM_LENKUNG, 220);
      digitalWrite(MOTOR_LENKUNG1, HIGH);
      digitalWrite(MOTOR_LENKUNG2, LOW);

      StopLenkungZeit = micros();
    }
    else 
    {
      digitalWrite(OUTPUT_ABSTAND, LOW);

      if ( micros() - StopLenkungZeit > 1200 * 1000) 
      {
        // Stoppe Lenkung
        analogWrite(PWM_RICHTUNG, Geschwindigkeit * 0.8);

        analogWrite(PWM_LENKUNG, 0);
        digitalWrite(MOTOR_LENKUNG1, LOW);
        digitalWrite(MOTOR_LENKUNG2, LOW);        
      }
    }
  }

  // Richtung auf stopp
  analogWrite(PWM_RICHTUNG, 0);
  digitalWrite(MOTOR_RICHTUNG1, LOW);
  digitalWrite(MOTOR_RICHTUNG2, LOW);


  // Lenkung auf stopp
  analogWrite(PWM_LENKUNG, 0);
  digitalWrite(MOTOR_LENKUNG1, LOW);
  digitalWrite(MOTOR_LENKUNG2, LOW);


/*
  //digitalWrite(MOTOR_RICHTUNG1, Taste1 == LOW ? HIGH : LOW);
  digitalWrite(MOTOR_RICHTUNG2, Taste2 == LOW ? HIGH : LOW);

  if (Taste1 == LOW)
  {  
    tone(8, 50);
  }    
  else
  {
    noTone(8);
  }
  */









  delay(500);
}
