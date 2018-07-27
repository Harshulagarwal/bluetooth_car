
int motor1Pin1 = 3; // left motor pin 1
int motor1Pin2 = 4; // left motor pin 2

int motor2Pin1 = 8; // right motor pin 1
int motor2Pin2 = 9; // right motor pin 2
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
    // sets enable1Pin and enable2Pin high so that motor can turn on:
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
   analogWrite(10,20);
   digitalWrite(11,LOW);
   analogWrite(12,20);
   digitalWrite(13,LOW);
   analogWrite(6,20);
   digitalWrite(7,LOW);
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is '1' the DC motor will go forward
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
          
   analogWrite(10,20);
   digitalWrite(11,LOW);
   analogWrite(12,20);
   digitalWrite(13,LOW);
   analogWrite(6,20);
   digitalWrite(7,LOW);
 
           delay(50);          
           if(flag == 0){
          Serial.println("move forward");
          flag=1;
        }
      }
    
        else if (state == 'L') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
                   
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,20);
   digitalWrite(13,LOW);
   analogWrite(6,0);
   digitalWrite(7,LOW);
                   delay(50);
                   if(flag == 0){
          Serial.println("Turn left");
          flag=1;
        }
        
    }
    // if the state is '3' the motor will Stop
    else if (state == 'S' || stateStop == '3') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
       
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,0);
   digitalWrite(13,LOW);
   analogWrite(6,0);
   digitalWrite(7,LOW);
           delay(50);
           if(flag == 0){
          Serial.println("stop");
          flag=1;
        }
        
    }
    // if the state is '4' the motor will turn right
    else if (state == 'R') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
                 
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,0);
   digitalWrite(13,LOW);
   analogWrite(6,20);
   digitalWrite(7,LOW);
                 delay(500);
        
                 if(flag == 0){
          Serial.println("Turn RIGHT");
          flag=1;
        }
        
    }
    // if the state is '5' the motor will Reverse
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
       
   analogWrite(10,20);
   digitalWrite(11,LOW);
   analogWrite(12,20);
   digitalWrite(13,LOW);
   analogWrite(6,20);
   digitalWrite(7,LOW);
           delay(50);
           if(flag == 0){
          Serial.println("reverse");
          flag=1;
        }
    }
    else if (state == 'G') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("backwards right ");
          flag=1;
          
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,0);
   digitalWrite(13,LOW);
   analogWrite(6,0);
   digitalWrite(7,LOW);
           delay(50);
        }
    }
    else if (state == 'H') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,0);
   digitalWrite(13,LOW);
   analogWrite(6,0);
   digitalWrite(7,LOW);
        if(flag == 0){
          Serial.println("Reverse left");
          flag=1;
           delay(50);
        }
    }
    else if (state == 'A') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,0);
   digitalWrite(13,LOW);
   analogWrite(6,0);
   digitalWrite(7,LOW);
        if(flag == 0){
          Serial.println("stop");
          flag=1;
           delay(50);
        }
    }
    else if (state == 'C') {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("stop");
          flag=1;
          
   analogWrite(10,0);
   digitalWrite(11,LOW);
   analogWrite(12,0);
   digitalWrite(13,LOW);
   analogWrite(6,0);
   digitalWrite(7,LOW);
           delay(50);
        }
    }
    }
