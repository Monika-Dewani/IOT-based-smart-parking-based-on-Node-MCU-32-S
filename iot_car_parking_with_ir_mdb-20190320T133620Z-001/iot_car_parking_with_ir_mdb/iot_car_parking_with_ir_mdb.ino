#include <WiFi.h>
#include <WiFiClient.h> 
#include <HTTPClient.h>
int f1 = 0,f2=0,f3=0;
const char *ssid =  "mdb";     // replace with your wifi ssid and wpa2 key
const char *pass =  "mdbelectrosoft";
int status;
String Link,Link1,Link2,Link3;
HTTPClient http,http1,http2,http3;
       String getstatus;
WiFiClient client;


void setup() {
  pinMode(27,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
  // put your setup code here, to run once:
 delay(1000);
  Serial.begin(115200);
 
  WiFi.begin(ssid, pass); 
  delay(1000);
{
  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Empty";
    http1.begin(Link1);     //Specify request destination
  
  int httpCode1 = http1.GET();            //Send the request
  String payload1 = http1.getString(); 
}
delay(5000);
{
  Link2="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led5.php?status=Empty";
    http2.begin(Link2);     //Specify request destination
  
  int httpCode2 = http2.GET();            //Send the request
  String payload2 = http2.getString(); 
}
delay(5000);
{
  Link3="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=Empty";
    http3.begin(Link3);     //Specify request destination
  
  int httpCode3 = http3.GET();            //Send the request
  String payload3 = http3.getString(); 
}

}

void loop() {

Serial.println("Hello");
Link="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/ShowLed3.php";
    http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  
//if(payload=="1"){
//  if(f1 == 0)
//  {
//  digitalWrite(27,HIGH);
//  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Book";
//    http1.begin(Link1);     //Specify request destination
//  
//  int httpCode1 = http1.GET();            //Send the request
//  String payload1 = http1.getString();    //Get the response payload
// 
//  Serial.println(httpCode1);   //Print HTTP return code
//  Serial.println(payload1);    //Print request response payload
//  Serial.println("send successfully"); 
//  }
//if (analogRead(33) > 500)
//{
//  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Park";
//    http1.begin(Link1);     //Specify request destination
//  
//  int httpCode1 = http1.GET();            //Send the request
//  String payload1 = http1.getString();    //Get the response payload
// f1=1;
// 
//}
//else if(f1 == 1);
//{
//  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Empty";
//    http1.begin(Link1);     //Specify request destination
//  
//  int httpCode1 = http1.GET();            //Send the request
//  String payload1 = http1.getString(); 
//}
  
 delay(1000);
}

 


