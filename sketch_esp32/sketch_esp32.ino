#include <SoftwareSerial.h>
#include <PubSubClient.h>


#define TOPICO_SUBSCRIBE1 "" //Publish
/* Tópico MQTT para envio de informações do ESP32 para broker MQTT */
#define TOPICO_PUBLISH1   "" // Subscrib
#define TOPICO_PUBLISH2   "" // Subscrib

#define ID_MQTT  "" 
const char* SSID = "trabprogdistribuida"; 
const char* PASSWORD = "unoesc123"; 

int greenLED = 33;
int redLED = 18;
int rearm = 32;
int activate = 21;
int alarmPin = 25;



#define rxPin 2
#define txPin 4

// Set up a new SoftwareSerial object
SoftwareSerial portOne(2, 4);



void setup() {
  Serial.begin(9600);
  
 // Define pin modes for TX and RX
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    
    // Set the baud rate for the SoftwareSerial object
    portOne.begin(9600);
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  pinMode(rearm, INPUT);
  pinMode(activate, INPUT);
}


void loop() {
  if (portOne.isListening()) { 
        Serial.println("portOne is listening!");
    }
  // read the analog / millivolts value for pin 2:
  digitalWrite(greenLED, HIGH);
  int activated = digitalRead(activate);
  Serial.print(activated);
  Serial.print("\n");
  if (activated) {
    digitalWrite(redLED, HIGH);
    tone(alarmPin, 440, 10);
  }
  int des = digitalRead(rearm);
  
  if (des) {
    digitalWrite(redLED, LOW);
  }
}
