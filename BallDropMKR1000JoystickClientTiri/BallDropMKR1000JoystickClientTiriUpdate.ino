/*
  Joystick client

  This program reads a joystick on A0 and A1, with
  the pushbutton on pin 5. It uses those values to connect
  to a game server.
  Written and tested on a MKR1000

  created 20 Jun 2012
  modified 20 Feb 2016
  by Tom Igoe
  modified for Tiri controller 10 sep 2017 by Tiri
*/

#include <SPI.h>
#include <WiFi101.h>

const char ssid[] = "itpsandbox";       //  your network SSID (name)
const char pass[] = "NYU+s0a!+P?";   // your network password

WiFiClient client;                // instance of the WIFi client library
int status = WL_IDLE_STATUS;      // WiFi status
IPAddress server(172, 22, 151, 123);    // address of the server

const int connectButton = 5;      // the pushbutton for connecting/disconnecting
const int connectionLED = 6;      // this LED indicates whether you're connected

const int sendInterval = 100;     // minimum time between messages to the server
const int debounceInterval = 15;  // used to smooth out pushbutton readings
int prevButtonState = 0;          // previous state of the pushbutton
long lastTimeSent = 0;            // timestamp of the last server message

int previousValueX = 0;
int previousValueY = 0;
sensorValueX = int(map(sensorValueX, 0, 1023, -6, 6));
sensorValueY = int(map(sensorValueY, 0, 1023, -15, 15));
//when move the slider to the right
if (sensorValueX > previousValueX) {
  Serial.print('r');
  client.print('r');
  //when move the slider to the left
} else if (sensorValueX < previousValueX) {
  Serial.print('l');
  client.print('l');
}
previousValueX = sensorValueX;
//when move the slider to the up
if (sensorValueY > previousValueY) {
  Serial.print('u');
  client.print('u');
  //when move the slider to the down
} else if (sensorValueY < previousValueY) {
  Serial.print('d');
  client.print('d');
}

//to set the possition of slide to the previous value
previousValueY = sensorValueY;


  if (client.connected()                     // if the client's connected
      && now - lastTimeSent > sendInterval   // and the send interval has elapased
      && message != 0) {                     // and there's a message to send
    client.print(message);                   // send a message
    Serial.print(message);
    //save this moment as last time you sent a message:
    lastTimeSent = now;
  }

  // set the connection LED based on the connection state:
  digitalWrite(connectionLED, client.connected());

  // if there's incoming data from the client, print it serially:
  if (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
}

// this method reads the button to see if it's just changed
// from high to low, and debounces the button:
boolean buttonRead(int thisButton) {
  boolean result = false;
  int currentState = digitalRead(thisButton); // current button state

  if (currentState != prevButtonState         // if the button's changed
      && currentState == LOW) {               // and it's low
    result = true;                            // result is true
  }

  delay(debounceInterval);                    // debounce delay
  prevButtonState = currentState;             // save the button state for next time
  return result;
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
