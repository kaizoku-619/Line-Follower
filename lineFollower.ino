//setting the sensors pins
int rightPin=2;
int centerPin=3;
int leftPin=4;
//setting the motors driver pins
int rightMotorF=10;
int rightMotorB=5;
int leftMotorF=6;
int leftMotorB=9;
//stop both motors
void Stop(){
  analogWrite(rightMotorF, 0);
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, 0);
  analogWrite(leftMotorB, 0);
}
//move both motors forward
void Forward(){
  analogWrite(rightMotorF, 140);
  analogWrite(leftMotorB, 140);
  analogWrite(rightMotorF, 140);
  analogWrite(leftMotorB, 140);
}
//move both motors backwards
void Backward(){	
  analogWrite(rightMotorF, 0);
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, 140);
  analogWrite(leftMotorB, 140);
}
//move the right motor forward to turn right
void Right(){
  analogWrite(rightMotorF, 140);
  analogWrite(leftMotorB, 0);
  analogWrite(rightMotorF, 140);
  analogWrite(leftMotorB, 0);
}
//move the left motor forward to turn left
void Left(){
  analogWrite(rightMotorF, 0);
  analogWrite(leftMotorB, 140);
  analogWrite(rightMotorF, 0);
  analogWrite(leftMotorB, 140);
}

// the setup routine runs once when you press reset:
void setup() {                
  // set the sensors pins mode to inputs
  pinMode(rightPin, INPUT);
  pinMode(centerPin, INPUT);
  pinMode(leftPin, INPUT);
  // set the motors driver pins mode to outputs
  pinMode(rightMotorF, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(leftMotorF, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //read the sensors state
  int rightState = digitalRead(rightPin);
  int centerState = digitalRead(centerPin);
  int leftState = digitalRead(leftPin);
  if (rightState==HIGH && centerState==LOW && leftState==HIGH){
  	Forward();
  }
  else if (rightState==LOW && leftState==HIGH){
  	Left();
  }
  else if (rightState==HIGH && leftState==LOW){
  	Right();
  }
  else {
  	Stop();
  }
}
