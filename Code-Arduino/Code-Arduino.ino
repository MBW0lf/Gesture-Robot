// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
double x,y,z;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial1.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  x=(Wire.read()<<8|Wire.read());  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  y=(Wire.read()<<8|Wire.read());  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  z=(Wire.read()<<8|Wire.read());  
  Serial.print(x);
  Serial.print(' ');
  Serial.print(y);
  Serial.print(' ');
  Serial.print(z);
  Serial.print('\n');

  if(x>=9500)
  {
    if(y>=10500)
        Serial1.print('A');
    else if(y<10500 && y>=4500)
        Serial1.print('a');
    else if(y<4500 && y>=-2000)
        Serial1.print('N');
    else if(y<-2000 && y>=-8500)
        Serial1.print('b');
    else if(y<-8500)
        Serial1.print('B');
  }
  else if(x<9500 && x>=5000)
  {
    if(y>=4500)
        Serial1.print('a');
    else if(y<4500 && y>=-2000)
        Serial1.print('n');
    else if(y<-2000)
        Serial1.print('b');
  }
  else if(x<5000 && x>=-2500)
  {
    if(y>=10500)
        Serial1.print('W');
    else if(y<10500 && y>=4500)
        Serial1.print('w');
    else if(y<4500 && y>=-2000)
        Serial1.print('O');
    else if(y<-2000 && y>=-8500)
        Serial1.print('e');
    else if(y<-8500)
        Serial1.print('E');
  }
  else if(x<-2500 && x>=-5000)
  {
    if(y>=4500)
        Serial1.print('c');
    else if(y<4500 && y>=-2000)
        Serial1.print('s');
    else if(y<-2000)
        Serial1.print('d');
  }
  else if(x<-5000)
  {
    if(y>=10500)
        Serial1.print('C');
    else if(y<10500 && y>=4500)
        Serial1.print('c');
    else if(y<4500 && y>=-2000)
        Serial1.print('S');
    else if(y<-2000 && y>=-8500)
        Serial1.print('d');
    else if(y<-8500)
        Serial1.print('D');
  }  

  
  delay(100);
}
