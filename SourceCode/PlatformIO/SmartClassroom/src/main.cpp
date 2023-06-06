//==============================================================================================//
// Project - Smart-Classroom-Environment-Management-System
// Author - (Hackster ID - maheshyadav216 ) : https://www.hackster.io/maheshyadav2162
// Contest - Project for Hackster Contest - Smart Campus 2023 : Technologies for a more sustainable campus lifestyle
// Organizers - hackster.io and DFRobot
// GitHub Repo of Projet - https://github.com/maheshyadav216/Smart-Classroom-Environment-Management-System
// Code last Modified on - 06/06/2023
//===============================================================================================//

#include <Arduino.h>
#include <WiFi.h>
#include <Arduino_ESP32_OTA.h>
#include "arduino_secrets.h"
#include "thingProperties.h"


// put function declarations here:

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  Serial.println("Initilizing Env-sensor...");
  while(environment.begin() != 0){
  Serial.println(" Sensor initialize failed!!");
  delay(1000);
  }
  Serial.println(" Sensor  initialize success!!");
  delay(500);

  init_GPIO();
  delay(500);
  
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  getReadings();
  sendTemperatureToNextion();
  sendHumidityToNextion();
  sendAirToNextion();
  sendDustToNextion();
  sendNoiseToNextion();
  sendLightToNextion();
}