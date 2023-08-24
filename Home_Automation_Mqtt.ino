//Home Automation Project - By - Steve Nathan de Sa

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/**WiFi Access Point**/

#define WLAN_SSID       "Pixel"
#define WLAN_PASS       "stevedesasnd7"

/**Adafruit.io Setup**/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "stevedesa"
#define AIO_KEY         "f92e4c1f207b49dd827a31af59a30514"

/**Global State**/

// Create an ESP8266 WiFiClient class to connect to the MQTT server. // WiFiClient client; or WiFiClientSecure client;(SSL)
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/**Feeds**/

// Feeds for publishing.
Adafruit_MQTT_Subscribe relays = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relays");

/**Code**/

void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println("Home Automation Project - By Steve Nathan de Sa");

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());

  // Setting up MQTT subscription for relay feeds.
  mqtt.subscribe(&relays); 
  
  // Setting up relay pins
  pinMode(16, OUTPUT); //Relay 1 - 16
  pinMode(5, OUTPUT);  //Relay 2 - 5
  digitalWrite(16, HIGH); //Relay 1 - LOW (INITIALLY)
  digitalWrite(5, HIGH
  
  );  //Relay 2 - LOW (INITIALLY)
}

void MQTT_connect() //Connecting to the MQTT Server for publishing
{
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) 
  {
    return;
  }
  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) 
       { // connect will return 0 for connected
        Serial.println(mqtt.connectErrorString(ret));
        Serial.println("Retrying MQTT connection in 5 seconds...");
        mqtt.disconnect();
        delay(5000);  // wait for 5 seconds
        retries--;
         if (retries == 0) 
         { // basically die and wait for WDT to reset me
         while (1);
         }
       }
  Serial.println("MQTT Connected!");
}

void loop() 
{
  MQTT_connect();

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) 
  {
    if (subscription == &relays) 
    {
      String last = (char *)relays.lastread;
      Serial.println(last);

      if(last == "R1A") 
      {
        digitalWrite(16, LOW); //RELAY 1 ON
      }
      else if(last == "R1B")
      {
        digitalWrite(16, HIGH);  //RELAY 1 OFF
      }
    
      if(last == "R2A")
      {
        digitalWrite(5, LOW); //RELAY 2 ON
      }
      else if(last == "R2B")
      {
        digitalWrite(5, HIGH);  //RELAY 2 OFF
      }
      
      if(last == "12A")
      {
        digitalWrite(16, LOW); //RELAY 1 ON
        digitalWrite(5, LOW);  //RELAY 2 ON
      }
      else if(last == "12B")
      {
        digitalWrite(16, HIGH); //RELAY 1 OFF
        digitalWrite(5, HIGH);  //RELAY 2 OFF
      }
    }
  } 
}
