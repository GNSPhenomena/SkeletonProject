const int trigPin = 9;
const int echoPin = 10;

int redPin = 3;
int greenPin = 5;
int bluePin = 6;

int speakerPin = 8;

void setup()
{ 
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void showRGB(int color)
{
  int redIntensity;
  int greenIntensity;
  int blueIntensity;
  
  if(color == 0)
  {
    redIntensity = 0;    
    greenIntensity = 0;        
    blueIntensity = 0; 
  }
  else if (color <= 255)
  {
    redIntensity = 255 - color;   
    greenIntensity = color;      
    blueIntensity = 0;           
  }
  else if (color <= 511)
  {
    redIntensity = 0;                
    greenIntensity = 255 - (color - 256); 
    blueIntensity = color - 256;        
  }
  else if (color <= 768) 
  {
    redIntensity = color - 512;        
    greenIntensity = 0;               
    blueIntensity = 255 - (color - 512);  
  }
  else
  {
    redIntensity = 255;
    greenIntensity = 255;
    blueIntensity = 255;
  }
  analogWrite(redPin, redIntensity);
  analogWrite(bluePin, blueIntensity);
  analogWrite(greenPin, greenIntensity);
}

void loop() {
  //ultrasonic
  long duration,distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Distance: ");
  Serial.println(distance);
  //conditions
  if(distance < 50) 
  {
    showRGB(800);
    delay(10);
    //tone(speakerPin,distance*35);
  }
  else if(distance > 120)
  {
    showRGB(0);
    delay(10);
    //tone(speakerPin,-1);
  }
  else
  {
    showRGB((distance-50)*12);
    delay(10);
    //tone(speakerPin,distance*35);
  }
}