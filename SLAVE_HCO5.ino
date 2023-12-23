#include <SoftwareSerial.h>

#define BT_NAME   "BT_Slave"

SoftwareSerial mySerial(8,9); // RX, TX
int ena = 5;
int in1 = 6;-
int in2 = 7;
int enb=  2;
int in3=  4;
int in4=  3;


char c='0';
int dt=200;
void setup()
{
  Serial.begin(38400);

  mySerial.begin(38400);
  
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);


  
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
   Serial.begin(38400);

 delay(dt);

  Serial.println("Arduino receiver");

//   mySerial.print("AT\r\n");
//   delay(200);
//   mySerial.print("AT+RMAAD\r\n");
//   delay(200);
//   mySerial.print("AT+ADDR?\r\n");
//   delay(200);

//   mySerial.print("AT+NAME="+String(BT_NAME)+"\r\n");
//   delay(200);
//   mySerial.print("AT+PSWD=\"1234\"\r\n");
//   delay(200);
//   mySerial.print("AT+ROLE?\r\n");
//   delay(200);
//   mySerial.print("AT+UART=38400,0,0\r\n");
//   delay(500);
 }

void loop()
{
 if(mySerial.available() >1)
 {
 c=(char)mySerial.read();



     Serial.print("x "); 
        Serial.println((char)mySerial.read()); 
        
 delay(10);

        
        }
         if(c=='1')
 {
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 150 );
    digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 150);
 }
 if(c=='a')
 {
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 255 );
    digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 255 );
 }
 if(c=='5')
 {digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, 150 );
    digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 150 );
  
 }
 if(c=='b')
 {digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, 255);
    digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 255 );
  
 }

    

if(c=='7')
 {
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 170 );
    digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  
 }
 if(c=='d')
 {
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 255 );
    digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  
 }
if(c=='3')
 {
   digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
    digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 170 );
 }
if(c=='c')
 {
   digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
    digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 255);
 }

if(c=='2'||c=='6')
{
   digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(ena, 255);
    digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 255);
}
if(c=='8'||c=='4')
{
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena, 255);
    digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 255);
}
if(c=='0')
{ digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
}
 delay(50);


} 

