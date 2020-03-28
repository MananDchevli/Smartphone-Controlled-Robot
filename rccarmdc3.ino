//mdc2
//speed of motors betwen 0 and 255, if you like you can change it
// front lights: connect anode of LED(long leg) to pin 8 and cathode(short) to ground (GND) and also connect a resistor in between
// back lights: connect anode of LED(long leg) to pin 7 and cathode(short) to ground (GND)and also connect a resistor in between
// horn: connect red wire of buzzer to pin 4 and black to ground (GND) and also connect a resistor in between
int pwm_speedA = 255;
int pwm_speedB = 240;
char command;
 
void setup() 
{
Serial.begin(9600);
//pins for motor controller
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
 
}
 
void loop() {
 
if(Serial.available() > 0)
{
  command = Serial.read();
  motors_stop();
  switch(command)
  {
      case 'F':
      forward();
      break;
      case 'B':
      backward();
      break;
      case 'L':
      left();
      break;
      case 'R':
      right();
      break;
      case 'W':  
      digitalWrite(8, HIGH);
      break;
      case 'w':  
      digitalWrite(8, LOW);
      break;
      case 'U': 
      digitalWrite(7, HIGH);
      break;
      case 'u':  
      digitalWrite(7, LOW);
      break; 
      case 'V':  
      tone(4, 1000);
      delay(1000);
      noTone(4);
      break;
      case 'v':  
      noTone(4);
      break;
      case 'S':  
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      break;
              
  }
}
 
}
 
// function for driving straight
void forward(){
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
 
digitalWrite(9, HIGH);
digitalWrite(6, LOW);
 
analogWrite(5, pwm_speedA);
analogWrite(3, pwm_speedB);
}
 
//function for reversing
void backward(){
 
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
 
digitalWrite(9, LOW);
digitalWrite(6, HIGH);
 
analogWrite(5, pwm_speedA);
analogWrite(3, pwm_speedB);
}
 
//function for turning left
void left(){
digitalWrite(11, LOW);
digitalWrite(10, LOW);
 
digitalWrite(9, HIGH);
digitalWrite(6, LOW);
 
analogWrite(3, 0);
analogWrite(5, pwm_speedA);
}
 
//function for turning right
void right(){
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
 
 
digitalWrite(9, LOW);
digitalWrite(6, LOW);
 
analogWrite(3, pwm_speedB);
analogWrite(5, 0);
 
}
 
//function for stopping motors
void motors_stop(){
 
digitalWrite(11, LOW);
digitalWrite(10, LOW);
 
digitalWrite(9,LOW);
digitalWrite(6, LOW);
 
analogWrite(5, 0);
analogWrite(3, 0);
}
