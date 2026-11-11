#define BLYNK_TEMPLATE_ID "Your_Template ID"
#define BLYNK_TEMPLATE_NAME "Your_Template_Name"
#define BLYNK_AUTH_TOKEN "Your_Token"

/*** LIBRARIES ****/
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*** WIFI ****/
char ssid[] = "Your_Wifi_Name";
char pass[] = "Your_Wifi_Password";

/*** OUTPUT PINS ****/
#define OUTPUT0 D2
#define OUTPUT1 D5
#define OUTPUT2 D6
#define OUTPUT3 D1

/*** SETUP ****/
void setup()
{
  Serial.begin(115200);

  pinMode(OUTPUT0, OUTPUT);
  pinMode(OUTPUT1, OUTPUT);
  pinMode(OUTPUT2, OUTPUT);
  pinMode(OUTPUT3, OUTPUT);

  digitalWrite(OUTPUT0, HIGH);
  digitalWrite(OUTPUT1, HIGH);
  digitalWrite(OUTPUT2, HIGH);
  digitalWrite(OUTPUT3, HIGH);

  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connected!");
}

/*** BUTTON V0 ****/
BLYNK_WRITE(V0)
{
  int value = param.asInt();
  digitalWrite(OUTPUT0, value);
}

/*** BUTTON V1 ****/
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  digitalWrite(OUTPUT1, value);
}

/*** BUTTON V2 ****/
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  digitalWrite(OUTPUT2, value);
}

/*** BUTTON V3 ****/
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  digitalWrite(OUTPUT3, value);
}

/*** LOOP ****/
void loop()
{
  Blynk.run();
}
