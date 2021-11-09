#include <WiFi.h>
#include <WiFiClient.h>  
#include <ESP8266HTTPClient.h>
const char *ssid =  "sk";     // replace with your wifi ssid and wpa2 key
const char *pass =  "sksheikh";
int status;

       String getstatus;
WiFiClient client;
void setup() {
  pinMode(D1,HIGH);
  // put your setup code here, to run once:
 delay(1000);
  Serial.begin(115200);
 
  WiFi.begin(ssid, pass); 
}

void loop() {
String Link,Link1;
HTTPClient http;

   if(WiFi.status() != WL_CONNECTED){
    delay(1000);
    status=0;    
    }else{
      delay(1000);
      status=1;
     }
 getstatus=String(status);
Serial.println(getstatus); 



Link="http://mahavidyalay.in/AcademicDevelopment/Smartbike/WifiStatus.php?status="+getstatus;
    http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 



//----------------------------------------------//------------------------------------//
  Link1="http://mahavidyalay.in/AcademicDevelopment/Smartbike/BikeStatus.php";
    http.begin(Link1);     //Specify request destination
  
  int httpCode1 = http.GET();            //Send the request
  String payload1 = http.getString();    //Get the response payload
 
  Serial.println(httpCode1);   //Print HTTP return code
  Serial.println(payload1);    //Print request response payload
payload1.setCharAt(0, '1');
payload1.setCharAt(2, '1');
  Serial.println(payload1); 
//String sa=""1""
 if(payload1=="111"){
 digitalWrite(D1,HIGH);
  
 }else{
   digitalWrite(D1,LOW);

  }
 
  http.end();  //Close connection

  delay(5000);
}
