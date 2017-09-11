/*
  Joystick client

  This program reads a joystick on A0 and A1, with
  the pushbutton on pin 5. It uses those values to connect
  to a game server.
  Written and tested on a MKR1000

  created 20 Jun 2012
  modified 20 Feb 2016
  by Tom Igoe
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
  if (sensorValueX > previousValueX) {
    Serial.print('r');
    client.print('r');
  } else if (sensorValueX < previousValueX) {
    Serial.print('l');
    client.print('l');
  }
  previousValueX = sensorValueX;

  if (sensorValueY > previousValueY) {
    Serial.print('u');
    client.print('u');
  } else if (sensorValueY < previousValueY) {
    Serial.print('d');
    client.print('d');
  }
  previousValueY = sensorValueY;



  //  if (sensorValueX > 200 && sensorValueX < 700) {
  ////    Serial.println(sensorValueX);
  //    Serial.print('l');
  //    client.print('l');
  //  } else if (sensorValueX > 700) {
  ////    Serial.println(sensorValueX);
  //    Serial.print('r');
  //    client.print('r');
  //  }
  //  if (sensorValueY > 200 && sensorValueY < 700) {
  //    Serial.print('u');
  //    client.print('u');
  //  } else if (sensorValueY > 700) {
  //    Serial.println(sensorValueY);
  //    Serial.print('d');
  //    client.print('d');
  //  }
