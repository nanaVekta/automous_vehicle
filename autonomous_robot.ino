//define pin numbers
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

const int motor1pin1 = 2;
const int motor1pin2 = 3;

const int motor2pin1 = 4;
const int motor2pin2 = 5;

// define variables
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Reads the echoPin, returns the sound wave time in microseconds
  duration = pulseIn(echoPin, HIGH);

  //calculate distance
  distance = duration*0.034/2;

  if(distance < 30){
    digitalWrite(13, HIGH);
    //reverse vehicle
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(1000);
  }
  else{
    digitalWrite(13, LOW);
    //move vehicle forward
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
  
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);    
  }
}
