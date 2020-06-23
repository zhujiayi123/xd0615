int pinInterrupt = 7; //接中断信号的脚
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), loop, CHANGE);
}

int i=0;
byte income=0;
void loop()
{
  for(i=0;i<11;i++)
  {
    income=income-'0';
    digitalWrite(2,income&0x1);
    digitalWrite(3,(income>>1)&0x1);
    digitalWrite(4,(income>>2)&0x1);
    digitalWrite(5,(income>>3)&0x1);
  	delay(1000);
    income++;
  }
  if(i=10) i=0;
  if ( digitalRead(pinInterrupt) == LOW ) 
  {
    income=0;
    i=0;
  }
     
}