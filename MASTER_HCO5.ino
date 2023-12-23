#include <SoftwareSerial.h>

#define BT_NAME   "BT_Master"

#define SLAVE_ADDRESS "0023,05,00319E"  //98d3:31:8095c3
const long baudRate = 38400; 
char c[16];
boolean NL = true;
SoftwareSerial mySerial(8,9); // RX, TX
int Xpin=A0;
int Ypin=A1;
int Spin=2;
String str="helo";
int Xval;
int Yval;
int Sval;
int dt=200;
char c1='11';
char c2='0';

void setup()
{
  Serial.begin(38400);
  
pinMode(Xpin,INPUT);
pinMode(Ypin,INPUT);
pinMode(Spin,INPUT);
digitalWrite(Spin,HIGH);
  mySerial.begin(38400);
  Serial.println("Arduino Sender");
  

digitalWrite(Spin,HIGH);

 delay(200);
 
   
}

void updateSerial(void)
{
}

void loop()
{
 Xval=analogRead(Xpin);
 delay(10);
 Yval=analogRead(Ypin);
 Sval=digitalRead(Spin);

   int n = 42;

if(Yval>535&&Yval<1010&&Xval<820&&Xval>128)
{
  c1='5';
}

if(Yval>=1010&&Yval<1025&&Xval<820&&Xval>400)
{
  c1='b';
}
if(Yval<=100&&Yval>25&&Xval<750&&Xval>400)
{
  c1='1';
}
if(Yval<=25&&Yval>=0&&Xval<1000&&Xval>300)
{
  c1='a';
}




if(Xval>535&&Xval<1020 &&Yval>350&&Yval<710)
{
  c1='7';
}
if(Xval>=1020&&Xval<1025&&Yval>150&&Yval<710)
{
  c1='d';
}
if(Xval<=480&&Xval>25&&Yval>190&&Yval<677)
{
  c1='3';
}
if(Xval<=25&&Xval>=0&&Yval>190&&Yval<860)
{
  c1='c';
}


if(Yval<120 &&Xval>1010)
{
  c1='8';
}
if(Yval>725 &&Xval>950)
{
  c1='6';
}
if(Yval<140 &&Xval<240)
{
  c1='2';
}
if(Yval>940 &&Xval<190)
{
  c1='4';
}

   Serial.print(c1);Serial.print(" ");Serial.print(Xval);Serial.print(" ");Serial.println(Yval);

delay(10);
// mySerial.print(c2);
      delay(100);
      mySerial.print(c1);
      c1='0';}
