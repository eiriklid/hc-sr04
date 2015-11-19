#include "Ultrasonic.h"
#include "Wire.h"
Ultrasonic ultrasonic(12,13);

void setup() {
  Serial.begin(9600);
  Wire.begin(1);
  Wire.onRequest(send_distance);
  
}

void loop()
{
  
  //Serial.print(ultrasonic.Timing());
  //Serial.print("\n");
  
}

void send_distance(){
  
  uint32_t distance = ultrasonic.Timing();
  Serial.print("Distance: \t");
  Serial.println(distance);
  //Wire.write(distance);
  
  uint8_t distance_array[4];
  distance_array[0]= ((distance >>24)& 0xFF);
  //Serial.println(distance_array[0]);
  
  distance_array[1]= ((distance >>16)& 0xFF);
  //Serial.println(distance_array[1]);
  
  distance_array[2]= ((distance >>8)& 0xFF);
  //Serial.println(distance_array[2]);
  
  distance_array[3]= ((distance)& 0xFF);
  //Serial.println(distance_array[3]);

  Wire.write(distance_array,4);
  
}

