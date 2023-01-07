void runsr04(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 음파 이동 시간을 계산해 저장 
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;   // 물체와의 거리를 cm으로 계산 
  
  Serial.print("Distance(cm): ");
  Serial.println(distanceCm);
  delay(300);

  if (distanceCm <= 15){
    flag = true;
    Serial.println("장애물 감지");
    digitalWrite(interOut, HIGH);
    upUDP();
    delay(5000);
    }  
}
