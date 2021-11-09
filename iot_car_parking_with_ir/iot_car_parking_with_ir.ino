#include <WiFi.h>
#include <WiFiClient.h> 
#include <HTTPClient.h>
int f1 = 0,f2=0,f3=0;   //flags to identify booked, empty or parked
int s1_ir = 33, s2_ir = 39, s3_ir = 32, se_ir = 36;   //IR Sensor receiver at section to sence car 
const char *ssid =  "mdb";     // replace with your wifi ssid and wpa2 key
const char *pass =  "mdbelectrosoft";
int status;

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
}

void loop() {
String Link,Link1,Link2,Link3;
HTTPClient http,http1,http2,http3;

   if(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
    }else{
      
Link="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/ShowLed3.php";
    http.begin(Link);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
 
   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  
if(payload=="1"){
  digitalWrite(27,HIGH);
  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Book";
    http1.begin(Link1);     //Specify request destination
  
  int httpCode1 = http1.GET();            //Send the request
  String payload1 = http1.getString();    //Get the response payload
 
  Serial.println(httpCode1);   //Print HTTP return code
  Serial.println(payload1);    //Print request response payload
  Serial.println("send successfully"); 
  f1=1;
if (analogRead(33) > 500)
{
  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Park";
    http1.begin(Link1);     //Specify request destination
  
  int httpCode1 = http1.GET();            //Send the request
  String payload1 = http1.getString();    //Get the response payload
 f1=0;
 
}
else if(f1==0)
{
  Link1="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Empty";
    http1.begin(Link1);     //Specify request destination
  
  int httpCode1 = http1.GET();            //Send the request
  String payload1 = http1.getString(); 
}
  
 
} 

//////////////////////////////////////////////////////2nd///////////////////////////////////



 else if (payload=="2")
 {
 digitalWrite(2,1);
Link2="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led5.php?status=Book";
    http2.begin(Link2);     //Specify request destination
  
  int httpCode2 = http2.GET();            //Send the request
  String payload2 = http2.getString();    //Get the response payload
 
  Serial.println(httpCode2);   //Print HTTP return code
  Serial.println(payload2);    //Print request response payload
  Serial.println("send successfully"); 
 f1=1;
if (analogRead(39) > 500)
{
  Link2="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led5.php?status=Parked";
    http2.begin(Link2);     //Specify request destination
  
  int httpCode2 = http2.GET();            //Send the request
  String payload2 = http2.getString();    //Get the response payload
 f1=0;
 
}
else if(f1==0)
{
  Link2="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led5.php?status=Empty";
    http2.begin(Link2);     //Specify request destination
  
  int httpCode2 = http2.GET();            //Send the request
  String payload2 = http2.getString(); 
}
 
  }


///////////////////////////////////////////////3rd//////////////////////////////////

 else if (payload=="3")
 {
 digitalWrite(0,1);
Link3="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=Book";
    http3.begin(Link3);     //Specify request destination
  
  int httpCode3 = http3.GET();            //Send the request
  String payload3 = http3.getString();    //Get the response payload
 
  Serial.println(httpCode3);   //Print HTTP return code
  Serial.println(payload3);    //Print request response payload
  Serial.println("send successfully"); 
 f1=1;
if (analogRead(32) > 500)
{
  Link3="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=Park";
    http3.begin(Link3);     //Specify request destination
  
  int httpCode3 = http3.GET();            //Send the request
  String payload3 = http3.getString();    //Get the response payload
 f1=0;
 
}
else if(f1==0)
{
  Link3="http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led6.php?status=Empty";
    http3.begin(Link3);     //Specify request destination
  
  int httpCode3 = http3.GET();            //Send the request
  String payload3 = http3.getString(); 
}
 
  }

  
else
{
digitalWrite(2,0);
digitalWrite(27,0);
digitalWrite(0,0);
}

    }
//----------------------------------------------//------------------------------------//
  
  http.end();  //Close connection

  delay(5000);
}
