//Home Automation Project - By Steve Nathan de Sa

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "Pixel"
#define WLAN_PASS       "stevedesasnd7"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "stevedesa"
#define AIO_KEY         "f92e4c1f207b49dd827a31af59a30514"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup feeds for publishing.
//Adafruit_MQTT_Publish relay_X = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/relay_X");

// Setup a feed called 'relayx' for subscribing to changes.
Adafruit_MQTT_Subscribe relay1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay1");
Adafruit_MQTT_Subscribe relay2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay2");
Adafruit_MQTT_Subscribe relay3 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay3");
Adafruit_MQTT_Subscribe relay4 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay4");
Adafruit_MQTT_Subscribe relay5 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay5");
Adafruit_MQTT_Subscribe relay6 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay6");


/*************************** Sketch Code ************************************/

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
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setting up MQTT subscription for relay feeds.
  mqtt.subscribe(&relay1); //Relay 1
  mqtt.subscribe(&relay2); //Relay 2
  mqtt.subscribe(&relay3); //Relay 3
  mqtt.subscribe(&relay4); //Relay 4
  mqtt.subscribe(&relay5); //Relay 5
  mqtt.subscribe(&relay6); //Relay 6
  
  // Setting up relay pins
  pinMode(16, OUTPUT); //Relay 1 - 16
  pinMode(5, OUTPUT);  //Relay 2 - 5
  pinMode(4, OUTPUT);  //Relay 3 - 4
  pinMode(14, OUTPUT); //Relay 4 - 14
  pinMode(12, OUTPUT); //Relay 5 - 12
  pinMode(13, OUTPUT); //Relay 6 - 13
  digitalWrite(16, LOW);
  digitalWrite(15, LOW);
  digitalWrite(14, LOW);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}


void loop() {
  MQTT_connect();

  //RELAY_1

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) 
  {
    if (subscription == &relay1) 
    {
      String last = (char *)relay1.lastread;
      Serial.println(last);

      if(last == "ON")
      {
        digitalWrite(16, HIGH);
      }
      else if(last == "OFF")
      {
        digitalWrite(16, LOW);
      }
    }
  } 
  
  //RELAY_2

  {
    if (subscription == &relay2) 
    {
      String last = (char *)relay2.lastread;
      Serial.println(last);

      if(last == "ON")
      {
        digitalWrite(15, HIGH);
      }
      else if(last == "OFF")
      {
        digitalWrite(15, LOW);
      }
    }
  } 

  //RELAY_3

  {
    if (subscription == &relay3) 
    {
      String last = (char *)relay3.lastread;
      Serial.println(last);

      if(last == "ON")
      {
        digitalWrite(14, HIGH);
      }
      else if(last == "OFF")
      {
        digitalWrite(14, LOW);
      }
    }
  } 

  //RELAY_4

  {
    if (subscription == &relay4) 
    {
      String last = (char *)relay4.lastread;
      Serial.println(last);

      if(last == "ON")
      {
        digitalWrite(13, HIGH);
      }
      else if(last == "OFF")
      {
        digitalWrite(13, LOW);
      }
    }
  }

   //RELAY_5

  {
    if (subscription == &relay5) 
    {
      String last = (char *)relay5.lastread;
      Serial.println(last);

      if(last == "ON")
      {
        digitalWrite(12, HIGH);
      }
      else if(last == "OFF")
      {
        digitalWrite(12, LOW);
      }
    }
  } 

  //RELAY_6
 
  {
    if (subscription == &relay6) 
    {
      String last = (char *)relay6.lastread;
      Serial.println(last);

      if(last == "ON")
      {
        digitalWrite(11, HIGH);
      }
      else if(last == "OFF")
      {
        digitalWrite(11, LOW);
      }
    }
  } 
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
