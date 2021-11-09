#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "mdb";
const char* password =  "mdbelectrosoft";
int s1_ir = 33, s2_ir = 39, s3_ir = 32, se_ir = 36;
HTTPClient http;   
String link1;
void setup() {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(100);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("Connected to WiFi");
   
 
}
 
void loop() 
{
 
 
 
    Serial.print("Sen1 = ");
   Serial.println(analogRead(s1_ir));
   if(analogRead(s1_ir) > 500)
      link1 = "http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Parked";
   else
      link1 = "http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Empty";
      
   http.begin(link1);  //Specify destination for HTTP request
 
  // http.begin("http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=ma");  //Specify destination for HTTP request
   //http.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int httpResponseCode = http.POST("post from 32s");   //Send the actual POST request
 
  
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 

 
 
 //  http.end();  //Free resources
 
 
  delay(5000);  //Send a request every 10 seconds
 
}
