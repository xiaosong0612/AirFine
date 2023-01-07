/*
 * 
 */

void setup_wifi(){
  delay(10);                      // start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to "); Serial.println(ssid);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  //Serial.println("WiFi connected");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

void Make_json(){
  //Serial.println(&timeinfo, "timeinfo %A, %B %d %Y %H:%M:%S");
  //strftime(strftime_buf, 20,"%X %x", &timeinfo);
  time_t rawtime;
  time(&rawtime);
  //sprintf(pubMsg, "\{\"%s\"\:%d, \"%s\"\:%s, \"%s\"\:%s\}", "t", rawtime, "C", currPosition, "P", prevPosition);
  //Serial.println(pubMsg);
}
