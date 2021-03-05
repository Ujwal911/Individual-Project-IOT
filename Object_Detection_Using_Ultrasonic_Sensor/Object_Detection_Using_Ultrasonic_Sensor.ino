int time = 1000;
int LED = 12;
int Buzzer = 13;
const int trigPin = 11;
const int echoPin = 10;
long duration;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);  
  Serial.begin(9600);
}

void loop()
{     
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);

  duration = pulseIn(echoPin, HIGH);
  int objectInCm= duration*0.034/2;
  
  Serial.print(objectInCm);
  Serial.print("cm - ");

  if (objectInCm < 15)
  {
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LED, HIGH);
    Serial.println("OBJECT TOO CLOSE!");
  }
  else
  {
    digitalWrite(Buzzer, LOW);
    digitalWrite(LED, LOW);
    Serial.println("NO OBJECT NEARBY");
  }
  delay(time);
}
