#include <WiFi.h>
#include <WiFiClient.h> 
#include <HTTPClient.h>
int f1 = 0,f2=0,f3=0;   //flags to identify booked, empty or parked
int s1_ir = 33, s2_ir = 39, s3_ir = 32, se_ir = 36;   //IR Sensor receiver at section to sence car 
const char *ssid =  "mdb";     // replace with your wifi ssid and wpa2 key
const char *pass =  "mdbelectrosoft";
int status;
String Link,link1,link2;
HTTPClient http;
String getstatus;
WiFiClient client;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
 
  WiFi.begin(ssid, pass); 
  delay(1000);
  if(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(50);
    }
    else
    { Serial.println(" ");
      Serial.println("Connected");
    }


}

void loop() {
 //  http.end();  //Free resources
 
 
    send_initialising_command();
      
    Link= "https://mahavidyalay.in/AcademicDevelopment/ServerDemo/ShowLed3.php";
    http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//http.end();
}

///////////////////////////////////Send Intitialising Command ////////////////////////////////

