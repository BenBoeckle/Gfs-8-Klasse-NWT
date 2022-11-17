# Gfs-8-Klasse-NWT

GFS Klasse 8 - Mikrokontroller gesteuertes Auto 

Arduino SW -- > Github
https://github.com/BenBoeckle/Gfs-8-Klasse-NWT.git

App and ESP32 Code --> Azure DevOps
https://boeckle.visualstudio.com/Ben%20GFS%208.%20Klasse%20NWT


## Präsentation Themen

### Eigenschaften, Überblick
- Basic Stamp
- Arduino
- ESP32 (Arduino kompatibel + WLAN + Bluetooth)

### Digital/Analog Eingänge
- Lesen schreiben
- Analog Ausgabe = PWM !!

### Abstandssensor
- Ultraschall
- Messung start mit Trigger (digital Ausgang)
- Sensor Mist Zeit für Schall hin und zurück, danach Ausgabe an digitalem Ausgang (Eingang für Mikrokontroller 
- High Signal solange das Signal gebraucht hat
- Messen der Zeit am Eingangs Pin (Echo) und über Schallgeschwindigkeit umrechnen in Abstand
- V = s/t  --> s = V*t  (Schallgeschwindigkeit * gemessene Zeit) / 2 (2 wegen hin und zurück)

### Motor
- Nicht direkt an Mikrokontroller (über LD293)
  - Zu wenig Strom
  - Art der Belastung zerstört Mikrokontroller (induktive Last)
- Vorwärts/rückwärts möglich mit LD293
- Geschwindigkeit --> PWM
- GFS Geschwindigkeit über Analog Eingang (Potentiometer) --> PWM Ausgabe
- Analog Eingang 0..1023, PWM 0.255 --> Analog Wert / 4 Ausgabe PWM

### Auto
- Motor Ansteuerung
- Abstandsensor
- Wifi
- AppSteuerung
- Geschwindkeit über App
- Lenkung über App
