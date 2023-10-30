
#include "Wire.h"


int dim_addr = 0x27;
void setup(){
  Wire.begin();
  Serial.begin(115200);
}

void send_dim_value(int dim_value){
  Wire.beginTransmission(dim_addr);
  Wire.write(0x80);
  Wire.write(dim_value);
  Wire.endTransmission();
  delay(100);
}
void loop(){
  //main loop

  Serial.println("Hello, beginning main loop!") ;
  for (int i = 40; i < 60 ; i++)
  {
    send_dim_value(i);
    Serial.println(i);
  }

  for (int i = 70; i > 40; i--)
  {
    send_dim_value(i);
    Serial.println(i);
  }

}