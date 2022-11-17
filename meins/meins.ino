#define TASTE1 2
#define TASTE2 3
#define TRIGGER 6
#define ECHO 7
#define MOTOR1 9 
#define MOTOR2 10
#define PWM 11 
#define LED_LEUCHTE 13


int counter = 0;

void setup() {
  pinMode(TASTE1, INPUT_PULLUP);
  pinMode(TASTE2, INPUT_PULLUP);  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(LED_LEUCHTE, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Taste1 = digitalRead(TASTE1);
  int Taste2 = digitalRead(TASTE2);

  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  long dauer = pulseIn(ECHO, HIGH);
  long entfernung = (dauer/2) * 0.03432; 
  if (entfernung  <=25)
   {
     digitalWrite(LED_LEUCHTE, HIGH);
   }
   else 
   {
      digitalWrite(LED_LEUCHTE, LOW);
   } 
  
  
  
  
  
  
  
  
  
  
  
  
  
  counter = counter + 1;
  if (counter>20) 
  {
    Serial.print("Taste1: ");
    Serial.print(Taste1);
    Serial.print(" Taste2: ");
    Serial.print(Taste2);
    Serial.println("");

    counter = 0;
  }
  
  
  
  delay(50);
  
 
 
 
 
 
  }  
 