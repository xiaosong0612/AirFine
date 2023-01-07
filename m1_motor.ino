void upUDP(){
  if(flag){
    Serial.println("BBBBBBBBBBBBBBBBBBBBBBB");
    udp.broadcastTo("s", UDPPORT);
    flag = false;
  }
}

void moveCar(char key){
  if(flag == true) {
    stopM();
  } else {
    Serial.print("key : ");Serial.println(key);

    switch(key){
      case 'f': forward(onestep); Serial.println("forward");    break;
      case 'L': leftSlide(onestep);  break;
      case 'l': left();        break;
      case 'R': rightSlide(onestep); Serial.println("rightSlide"); break;
      case 'r': right();   break;
      case 'b': backward(onestep);   break;
      case 'U': uTurn();      break;
      case 's': stopM(); Serial.println("stop");  break;
      defalut: Serial.println("key : unknown"); break;
    }
  }
 }
  

void forward(int ostep) {
    ledcWrite(fr1, MHIGH); ledcWrite(fr2, MLOW);
    ledcWrite(fl1, MHIGH); ledcWrite(fl2, MLOW);
    ledcWrite(br1, MHIGH); ledcWrite(br2, MLOW);
    ledcWrite(bl1, MHIGH); ledcWrite(bl2, MLOW);
    delay(onestep);
}

void backward(int ostep) {
    ledcWrite(fr1, MLOW);  ledcWrite(fr2, MHIGH);
    ledcWrite(fl1, MLOW);  ledcWrite(fl2, MHIGH);
    ledcWrite(br1, MLOW);  ledcWrite(br2, MHIGH);
    ledcWrite(bl1, MLOW);  ledcWrite(bl2, MHIGH);
    delay(ostep);
}

void rightSlide(int ostep){
    ledcWrite(fr1, MLOW);  ledcWrite(fr2, MHIGH);
    ledcWrite(fl1, MHIGH); ledcWrite(fl2, MLOW);
    ledcWrite(br1, MHIGH); ledcWrite(br2, MLOW);
    ledcWrite(bl1, MLOW);  ledcWrite(bl2, MHIGH);
    delay(ostep);
}

void leftSlide(int ostep){
    ledcWrite(fr1, MHIGH); ledcWrite(fr2, MLOW);
    ledcWrite(fl1, MLOW);  ledcWrite(fl2, MHIGH);
    ledcWrite(br1, MLOW);  ledcWrite(br2, MHIGH);
    ledcWrite(bl1, MHIGH); ledcWrite(bl2, MLOW);
    delay(ostep);
}

void uTurn(){
  ledcWrite(fr1, MLOW);  ledcWrite(fr2, MHIGH);
  ledcWrite(fl1, MHIGH); ledcWrite(fl2, MLOW);
  ledcWrite(br1, MLOW);  ledcWrite(br2, MHIGH);
  ledcWrite(bl1, MHIGH); ledcWrite(bl2, MLOW);
  delay(810);
  stopM();
}

void left(){
  ledcWrite(fr1, MHIGH); ledcWrite(fr2, MLOW);
  ledcWrite(fl1, MLOW);  ledcWrite(fl2, MHIGH);
  ledcWrite(br1, MHIGH); ledcWrite(br2, MLOW);
  ledcWrite(bl1, MLOW);  ledcWrite(bl2, MHIGH);
  delay(400);
  stopA();
  

}

void right(){
  ledcWrite(fr1, MLOW);  ledcWrite(fr2, MHIGH);
  ledcWrite(fl1, MHIGH); ledcWrite(fl2, MLOW);
  ledcWrite(br1, MLOW);  ledcWrite(br2, MHIGH);
  ledcWrite(bl1, MHIGH); ledcWrite(bl2, MLOW);
  delay(420); // mhigh 130, delay 550 직각
  stopA();
 
}

void stopM(){
  Serial.println("stopM");
  ledcWrite(fr1, MLOW); ledcWrite(fr2, MLOW);
  ledcWrite(fl1, MLOW); ledcWrite(fl2, MLOW);
  ledcWrite(br1, MLOW); ledcWrite(br2, MLOW);
  ledcWrite(bl1, MLOW); ledcWrite(bl2, MLOW);
  delay(6000);

}

void stopS(){
  flag = false;
  digitalWrite(interOut, LOW);
  Serial.println("interrupt occured...STOP!!..");
  ledcWrite(fr1, MLOW); ledcWrite(fr2, MLOW);
  ledcWrite(fl1, MLOW); ledcWrite(fl2, MLOW);
  ledcWrite(br1, MLOW); ledcWrite(br2, MLOW);
  ledcWrite(bl1, MLOW); ledcWrite(bl2, MLOW);
  delayMicroseconds(500);
}

void stopA(){
  ledcWrite(fr1, MLOW); ledcWrite(fr2, MLOW);
  ledcWrite(fl1, MLOW); ledcWrite(fl2, MLOW);
  ledcWrite(br1, MLOW); ledcWrite(br2, MLOW);
  ledcWrite(bl1, MLOW); ledcWrite(bl2, MLOW);
}
 
