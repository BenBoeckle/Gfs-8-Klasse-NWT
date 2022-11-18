# Gfs-8-Klasse-NWT

GFS Klasse 8 - Mikrokontroller gesteuertes Auto 

Web App Steuerung: 
https://wilhelmicar-web.azurewebsites.net

Arduino SW -- > Github
https://github.com/BenBoeckle/Gfs-8-Klasse-NWT.git

App and ESP32 Code --> Azure DevOps
https://boeckle.visualstudio.com/Ben%20GFS%208.%20Klasse%20NWT


## Präsentation Themen

### Eigenschaften, Überblick
- Basic Stamp
- Arduino
- ESP32 (Arduino kompatibel + WLAN + Bluetooth)

### GFS: Digital/Analog Eingänge
- Lesen schreiben
- Analog Ausgabe = PWM !!

### GFS: Abstandssensor
- Ultraschall
- Messung start mit Trigger (digital Ausgang)
- Sensor misst Zeit für Schall hin und zurück, danach Ausgabe an digitalem Ausgang (Eingang für Mikrokontroller 
- High Signal solange das Signal gebraucht hat
- Messen der Zeit am Eingangs Pin (Echo) und über Schallgeschwindigkeit umrechnen in Abstand
- V = s/t  --> s = V*t  (Schallgeschwindigkeit * gemessene Zeit) / 2 (2 wegen hin und zurück)

### GFS: Motor
- Nicht direkt an Mikrokontroller (über LD293)
  - Zu wenig Strom
  - Art der Belastung zerstört Mikrokontroller (induktive Last)
- Vorwärts/rückwärts möglich mit LD293
- Geschwindigkeit --> PWM

### GFS: Labor Aufbau
- Schalter digitale Eingänge starten Motor Vorwärts oder Rückwärts
- Poti stellt Helligkeit LED und Motor Geschwindigkeit über PWM ein
  - Wert über Analog Eingang 0..1023, PWM 0.255 --> Analog Wert / 4 Ausgabe PWM
- Abstandssensor schaltet LED an wenn Abstand < 10cm
  - Auto startet Lenkung anstatt LED


### GFS Auto - WilhelmiCar
- Motor Ansteuerung
- Abstandsensor
- Wifi
- AppSteuerung
- Geschwindkeit über App
- Lenkung über App

