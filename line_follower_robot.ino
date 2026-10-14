#define in1 10    //Left Motors
#define in2 9    
#define in3 5    //Right Motors
#define in4 3   

#define s1 12     // Left Sensor
#define s2 7      // Middle Sensor
#define s3 2      // Right Sensor

int left = 150;
int right = 150;
int forw = 110;

void setup ()
{
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  
  Serial.begin(9600);
}

void Forward()
{
  analogWrite(in1,forw);
  analogWrite(in2,0);
  analogWrite(in3,forw);
  analogWrite(in4,0);
}

void Right()
{
  analogWrite(in1,right);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,right);
}

void Left()
{
  analogWrite(in1,0);
  analogWrite(in2,left);
  analogWrite(in3,left);
  analogWrite(in4,0);
}


void Stop()
{
  analogWrite(in1,0);
  analogWrite(in4,0);
  analogWrite(in3,0);
  analogWrite(in2,0);
}

void loop ()
{
  int   IR1 = digitalRead(s1);
  int   IR2 = digitalRead(s2);
  int   IR3 = digitalRead(s3);

  // ONE SENSOR AT A TIME
  if (IR1 == LOW && IR2 == HIGH && IR3 == LOW)// STRAIGHT LINE
   {
      Forward();
      delay(150);
   }
  else if (IR1 == HIGH && IR2 == LOW && IR3 == LOW) // LEFT TURN
    {
      Left();
      delay(50);
    }
  else if (IR1 == LOW && IR2 == LOW && IR3 == HIGH) // RIGHT TURN
    {
      Right();
      delay(30);
    }
  // COMBINATION OF SENSORS
  else if (IR1 == HIGH && IR2 == HIGH && IR3 == LOW)// T-INTERSECTION LEFT
    {
      Left();// As Left is possible
      delay(150);
      Forward();
      delay(20);
    }

    else if (IR1 == LOW && IR2 == HIGH && IR3 == HIGH) // T-INTERSECTION RIGHT 
   { 
    Forward();
    delay(20);
   }

  else if (IR1 == HIGH && IR2 == LOW && IR3 == HIGH)// MIDDLE DEVIATED
    {
      Left();
      delay(20);
    }

  else if (IR1 == HIGH && IR2 == HIGH && IR3 == HIGH)// T-JUNCTION
    {
      Left();
      delay(10);
    }

  else if (IR1 == LOW && IR2 ==LOW && IR3 == LOW)// DEAD END
   {  Forward();
      delay(20);
      Left(); //As no other direction is possible
      delay(30);
   }
}
