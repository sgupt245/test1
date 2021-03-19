//hi my name is shiv
//this is the first ever change to the file

int rPin1 = A4;
int rVal1;
int servoPin = 15;
int servoChannel = 5;

int servoPos = 1;
int interval = 400;

unsigned long pm =0;
int motorPos = 1675;

int switchPin = 13;
int buttonPin = 27;
int n=0;
int tempInterval = 500;

int beaconVal;
int bigMotor = 1;

void setup() {


Serial.begin(2400);

ledcAttachPin(servoPin, servoChannel);    
ledcSetup(servoChannel, 50, 16);


pinMode(switchPin, INPUT);
pinMode(buttonPin, INPUT_PULLUP);


}

void loop() {


unsigned long cm = millis();

if(cm-pm>interval){
  pm= cm;

  
  switch (servoPos)
  {
    case 1:{
      servoPos=2;
      break;
    }
    case 2:{
      servoPos=3;
      break;
    }
    case 3:{
      servoPos=4;
      break;
    }
    case 4:{
      servoPos=5;
      break;
    }
    case 5:{
      servoPos=6;
      break;
    }
    case 6:{
      servoPos=1;
      break;
    }
    
  
  
}

if(servoPos==1){
  ledcWrite(servoChannel,0);
}

if(servoPos==2){
  ledcWrite(servoChannel,2013);
}


if(servoPos==3){
  ledcWrite(servoChannel,6038);
}
if(servoPos==4){
  ledcWrite(servoChannel,8050);
}
if(servoPos==5){
  ledcWrite(servoChannel,6038);
}


if(servoPos==6){
  ledcWrite(servoChannel,2013);
}



if(digitalRead(switchPin)==LOW){
  
  rVal1 = analogRead(rPin1);
  interval = map(rVal1, 0, 4096, 200, 1200);
  
  tempInterval = interval;
}

if(digitalRead(switchPin)==HIGH){
 
  if(digitalRead(buttonPin)==LOW){
    
    if(n==0){
      interval =100;
      n=1;
    }
    if(n==1){
      interval=interval+3;
    }
  }
  if(digitalRead(buttonPin) == HIGH){
    interval = tempInterval;
    n=0;
  }
}


}

beaconVal = Serial.read();

if(beaconVal!=-1){

bigMotor = 1;
  
}
else{
  bigMotor=0;
  ledcWrite(servoChannel,4025);
}

Serial.print("beaconVal");
Serial.println(beaconVal);


}
