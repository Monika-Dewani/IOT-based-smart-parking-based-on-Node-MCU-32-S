void send_initialising_command()
{
   Serial.print("Sen1 = ");
   Serial.println(analogRead(s1_ir));
   if(analogRead(s1_ir) > 500)
      link1 = "http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Parked";
   else
      link1 = "http://mahavidyalay.in/AcademicDevelopment/ServerDemo/Led4.php?status=Empty";
      
   http.begin(link1);  //Specify destination for HTTP request
   //http.addHeader("Content-Type", "text/plain");             //Specify content-type header
   int httpResponseCode = http.POST("post from 32s");   //Send the actual POST request
   String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
    
 
 
  delay(5000);  //Send a request every 10 seconds
 http.end();  //Free resources
}

