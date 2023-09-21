int s1;
int s2;
int s3;
int s4;
int s5;
int s6;
int s7;
int s8;
int s9;

const int LED1 = 4;
int flag=0;



const int ENA = 5;
const int IN1=10;//right side of motor when you see bot from back
const int IN2=11;
const int ENB = 6;//left side of motor when you see bot from back
const int IN3=9;
const int IN4=8;
void setup() 
{
  // put your setup code here, to run once:

  pinMode(LED1 , OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(7,INPUT);
  

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);

  //forward();
  //delay(2000);
}

void loop() 
{
flag=0;


  
  s1=digitalRead(A0);
  s2=digitalRead(A1);
  s3=digitalRead(A2);
  s4=digitalRead(A3);
  s5=digitalRead(A4);
  s6=digitalRead(A5);
  s7=digitalRead(2);
  s8=digitalRead(3);
  s9=digitalRead(7);


 /* Serial.print(s1);
  
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.print(s5);
  Serial.print(" ");
  Serial.print(s6);
  Serial.print(" ");
  Serial.print(s7);
  Serial.print(" ");
  Serial.print(s8);
  Serial.println(" ");
  delay (1000);*/


  if((s1==0)&&(s2==0)&&(s8==1)){
    left();
    delay(10);
  }
   if((s8==0)&&(s7==0)&&(s1==1)){
   right();
   delay(10);
  }
  
  //black=1
  //white=0
  //forward
  if(
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))
   //((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
  )
  {
    forward();
    
  }
  //right
  else if(
  
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||

  //((s1==0)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  //((s1==0)&&(s2==0)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
 // ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))
  )
  {
    right();
  }
  else if(
  
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  
 // ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  //((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==0)&&(s8==0))||
  //((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))
  
  )
  {  
    left();
  }
  else if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1)){ 
    motor_stop();
  /* delayMicroseconds(20);
    motor_rev();
    delayMicroseconds(2);*/
   left();
    delay(4);
    // right();
    //delayMicroseconds();
  }

  else if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0)&&(s9==1))
  { 
    motor_stop();
   //delay(1);
    //motor_rev(); 
    delayMicroseconds(20);
  }


  
  else if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s8==0)){
   // motor_stop();
    
 
 forward();
    analogWrite(LED1, 255);
     delayMicroseconds(20);
      
  // analogWrite(LED1, 0);
   
    

}
 /* else if((s9==0)){
   analogWrite(LED1, 255);
     delayMicroseconds(2);
  forward();
   
  
   
    

}*/
    
     
    
  else {
    forward1();
   
    }
  
  /*digitalWrite(trigPin, LOW);     //here things are commented out with help of slash
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  Serial.print("distance:----");
  
Serial.println(distance);
  
  if ( distance <= 10 )
  { 
    digitalWrite(LED1, HIGH);
    delayMicroseconds(3);
    digitalWrite(LED1, LOW);
    
  }
  else
  {
    digitalWrite(LED1, LOW);
  }*/
  analogWrite(LED1, 0);
  
}
void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 180);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 180);
   //delayMicroseconds(1);
}
void forward1()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100);
   //delayMicroseconds(1);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 80);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 80);
  //delayMicroseconds(5);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 80);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 80);
  //delayMicroseconds(5);
}

void motor_stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
void motor_rev()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 70);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 70);
  delay(3);

  if(s1==0||s2==0||s3==0||s4==0){
    left();
    delay(1);
   forward1();
  }
  else if(s5==0||s6==0||s7==0||s8==0){
    right();
      delay(1);
   forward1();
  }
  
}
