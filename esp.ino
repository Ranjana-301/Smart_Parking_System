#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
//WIFI DETAILS
char ssid[]="sanju";
char password[]="sanjana30";
//CHANNEL DETAILS
unsigned long channel_ID=2109972;
const char * APIkey="0FG1W8TR9CZ5WA0O";

const int Field_num_1=1;
String value="";
int value_1=0;
WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  Internet();
}

void loop() {
  Internet();
  if (Serial.available()>0)
  {
    delay(100);
    while(Serial.available()>0)
    {
     value=Serial.readString();
     if(value[0]=='*')
     {
      if(value[2]=='#')
      {
        value_1=value[1]-0x30;
      }
     }
    }
  }
  upload();
}
void Internet()
{
  if(WiFi.status()!= WL_CONNECTED)
  {
    while(WiFi.status()!= WL_CONNECTED)
    {
      WiFi.begin(ssid,password);
      delay(5000);
    }
  }
}
void upload()
{
 ThingSpeak.writeField(channel_ID,Field_num_1,value_1,APIkey);
 delay(15000);
 value="";
}
