/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  Rotate a servo using a slider!

  App project setup:
    Slider widget (0...180) on V3
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1f8b1235b4e5401d9dbb03ab7be7d806845210";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Not Connected Unsecured";
char pass[] = "pranith@10may845210";

Servo servo;
Servo servo2;
BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  servo2.write(param.asInt());
}

void setup()
{
  Blynk.begin(auth, ssid, pass);
  pinMode(4,OUTPUT);
  servo.attach(2);
  servo.write(0);
  servo2.attach(14);
  servo2.write(0);
}

void loop()
{
  Blynk.run();
}

