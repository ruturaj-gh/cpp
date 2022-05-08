#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>  //playground for collection of code

#include <LiquidCrystal_I2C.h>  //a library that deals with the LCD displays

#include <DHT.h> //an arduino library for the DHT series of low-cost temperature /humidity sensors

//dht11 is humidity-temperature sensor
#include <ESP8266WiFi.h>  //this library provides ESP8266 specific wi-fi routines that we are calling to connect to the network


String apiKey = "3W9Y4Y9GY4ZL1511";     //  Enter your Write API key here

const char *ssid =  "Nayan";     // Enter your WiFi Name
//service set identifier wireless network viewable with anyone with wireless device


const char *pass =  "nayanppagare"; // Enter your WiFi Password
const char* server = "api.thingspeak.com";
#define DHTPIN 14          // GPIO Pin where the dht11 is connected
//GPIO is an port that handles both incoming and outgoing digital signals . it is also used to connecting with cpu
 DHT dht(DHTPIN, DHT11); //initialising the dht sensors
 LiquidCrystal_I2C lcd (0x27, 16,2); //initialising the lcd  I2C address 0x27, 16 column and 2 rows

 const int PulseWire = A0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
 int bo = 0;
 int bo1=0;
const int LED13 = 13;  // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;
PulseSensorPlayground pulseSensor;
WiFiClient client;
void setup() {
  Serial.begin(115200); //it sets the baud rate for serial data communication.The baud rate signifies the data rate in bits per second.
 
  int  bo = analogRead(PulseWire);
   pulseSensor.analogInput(PulseWire);  
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold); //minimum threshold
 dht.begin();
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
       while (WiFi.status() != WL_CONNECTED)
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
  }

void loop() {
 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now.
  int  bo = analogRead(PulseWire);
if (pulseSensor.sawStartOfBeat())
{            // Constantly test to see if "a beat happened".
 Serial.println("♥️  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM:  ");                        // Print phrase "BPM: "
 Serial.println(myBPM);
 Serial.println(bo);

                   

}
 float h = dht.readHumidity();
      float t = dht.readTemperature();
     
              if (isnan(h) || isnan(t)) //isnan return true when there is not a number in its argument
                 {
                     Serial.println("Failed to read from DHT sensor!");
                      return;
                 }
                         if (client.connect(server,80))  //client library allows you to interact with the api
                      {  
                         bo1=bo/6.5;
                             // Serial.println(bo1);
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(bo1);
                             postStr +="&field3=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
                             Serial.print("Temperature: ");
                             Serial.print(t);
                              Serial.print("humidity: ");
                             Serial.print(h);
                             
                             Serial.print(" MY BPM: ");
                             Serial.print(myBPM);
                           
                              Serial.println(bo1);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
           Serial.println("Waiting...");
    delay(30000);
}