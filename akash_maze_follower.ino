// IR Sensor
#define leftCenterSensor   A3
#define leftNearSensor     A2
#define leftFarSensor      A1
#define rightCenterSensor  A4
#define rightNearSensor    A5
#define rightFarSensor     2

// IR Sensor readings
int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;

#define BLACK_LINE 0
#define WHITE_LINE 1

int leftNudge;
int replaystage;
int rightNudge;

// Enable Pins
#define enl 5   // LEFT
#define enr 6  // RIGHT

// speed of motor
#define spd 150

#define leapTime 200

// Motors
#define leftMotor1  11
#define leftMotor2  10
#define rightMotor1 13
#define rightMotor2 12

//for storing path details
char path[30] = {};
int pathLength;
int readLength;

void setup() {
  Serial.println("Setup");

  pinMode(leftCenterSensor, INPUT);
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(rightCenterSensor, INPUT);
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  pinMode(enl, OUTPUT);
  pinMode(enr, OUTPUT);

  Serial.begin(9600);
  Serial.println("Setup Done...");
}

void loop(){
  readSensors();
  //if only the middle two sensors can see the black line
  if(leftFarReading==BLACK_LINE && rightFarReading==BLACK_LINE && (leftCenterReading==WHITE_LINE || rightCenterReading==WHITE_LINE)) 
  {
    straight();                                                                                    
  }
  //otherwise goes to the leftHandWall method
  else
  {                                                                                              
    leftHandWall();                                                                                   
  }
}

void readSensors()  //accepts input from sensors
{
  leftCenterReading  = digitalRead(leftCenterSensor);
  leftNearReading    = digitalRead(leftNearSensor);
  leftFarReading     = digitalRead(leftFarSensor);
  rightCenterReading = digitalRead(rightCenterSensor);
  rightNearReading   = digitalRead(rightNearSensor);
  rightFarReading    = digitalRead(rightFarSensor); 
}


void leftHandWall(){
  if( leftFarReading==BLACK_LINE && rightFarReading==BLACK_LINE)  //indicates either 3way intersection or end of maze
  {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    readSensors();

    if(leftFarReading==BLACK_LINE || rightFarReading==BLACK_LINE) //if it moves forward and still sees all black, maze is done
    {
        done();
    }
    if(leftFarReading==WHITE_LINE && rightFarReading==WHITE_LINE) //otherwise it turns left
    { 
        turnLeft();
    }
  }
  
  if(leftFarReading==BLACK_LINE)  //indicates that a left turn is possible
  { 
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    readSensors();
    if(leftFarReading==WHITE_LINE && rightFarReading==WHITE_LINE) //checks to make sure maze isn't done
    {
      turnLeft();
    }
    else
    {
      done();
    }
  }
   
  if(rightFarReading==BLACK_LINE) //indicates a right turn is possible
  {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(10);  //CHANGED FROM 30 to 10
    readSensors();

    if(leftFarReading==BLACK_LINE)  //left turn is also possible
    {
      delay(leapTime-30);
      readSensors();

      if(rightFarReading==BLACK_LINE && leftFarReading==BLACK_LINE)//end of maze
      {
        done();
      }
      else  //make the left turn
      {
      turnLeft();
      return;
      }
    }
    delay(leapTime-30);
    readSensors();
    if(leftFarReading==WHITE_LINE && leftCenterReading==WHITE_LINE && rightCenterReading==WHITE_LINE && rightFarReading==WHITE_LINE)
    {
      turnRight();
      return;
    }
    path[pathLength] = 'S';
    pathLength++;
    if(path[pathLength-2] == 'B')
    {
      shortestPath();
    }
    straight();
  }
  readSensors();
  if(leftFarReading==WHITE_LINE && leftCenterReading==WHITE_LINE && rightCenterReading==WHITE_LINE 
    && rightFarReading==WHITE_LINE && leftNearReading==WHITE_LINE && rightNearReading==WHITE_LINE)
  {
    turnAround();
  }
}

void shortestPath()
{
  int shortDone = 0;
  if(path[pathLength-3] == 'L' && path[pathLength - 1] == 'R')
  {
    pathLength -= 3;
    path[pathLength] = 'B';
    shortDone = 1;
  }
  if(path[pathLength-3] == 'L' && path[pathLength - 1] == 'S' && shortDone == 0)
  {
    pathLength -= 3;
    path[pathLength] = 'R';
    shortDone = 1;
  }
  if(path[pathLength-3] == 'R' && path[pathLength - 1] == 'L' && shortDone == 0)
  {
    pathLength-=3;
    path[pathLength] = 'B';
    shortDone=1;
  }
  if(path[pathLength-3] == 'S' && path[pathLength - 1] == 'L' && shortDone == 0)
  {
    pathLength -= 3;
    path[pathLength] = 'R';
    shortDone = 1;
  }
  if(path[pathLength-3] == 'S' && path[pathLength - 1] =='S' && shortDone == 0)
  {
    pathLength-=3;
    path[pathLength] = 'B';
    shortDone=1;
  }
  if(path[pathLength-3] == 'L' && path[pathLength - 1] =='L' && shortDone == 0)
  {
    pathLength -= 3;
    path[pathLength] = 'S';
    shortDone = 1;
  }
  path[pathLength+1] = 'D';
  path[pathLength+2] = 'D';
  pathLength++;
}

void straight() {
  Serial.println("Move straight...");
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(enl, spd);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(enr, 180);
}

void turnLeft() {
  Serial.println("Trun Left...");
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(enl, spd);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(enr, spd);
}

void turnRight() {
  Serial.println("Trun Right...");
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(enl, spd);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(enr, spd);
}

void turnAround() {
  Serial.println("Trun Around...");
  turnLeft();
  turnLeft();
}

void done() {
  Serial.println("Done...");
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  analogWrite(enl, 0);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  analogWrite(enl, 0);
}
