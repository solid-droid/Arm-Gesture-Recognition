//Declaring some global variables

long gyro_x_cal, gyro_y_cal, gyro_z_cal;
long acc_x_cal, acc_y_cal, acc_z_cal;
boolean set_gyro_angles;

float angle_roll_acc, angle_pitch_acc;

float angle_pitch, angle_roll;
int angle_pitch_buffer, angle_roll_buffer;


long loop_timer;
int temp;

void setup_mpu_6050_registers(){
  //Activate the MPU-6050
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x6B);                                                    //Send the requested starting register
  Wire.write(0x00);                                                    //Set the requested starting register
  Wire.endTransmission();                                             
  //Configure the accelerometer (+/-8g)
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x1C);                                                    //Send the requested starting register
  Wire.write(0x10);                                                    //Set the requested starting register
  Wire.endTransmission();                                             
  //Configure the gyro (500dps full scale)
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x1B);                                                    //Send the requested starting register
  Wire.write(0x08);                                                    //Set the requested starting register
  Wire.endTransmission();                                             
}


void read_mpu_6050_data(){                                             //Subroutine for reading the raw gyro and accelerometer data
  Wire.beginTransmission(0x68);                                        //Start communicating with the MPU-6050
  Wire.write(0x3B);                                                    //Send the requested starting register
  Wire.endTransmission();                                              //End the transmission
  Wire.requestFrom(0x68,14);                                           //Request 14 bytes from the MPU-6050
  while(Wire.available() < 14);                                        //Wait until all the bytes are received
  acc_x = Wire.read()<<8|Wire.read();                                  
  acc_y = Wire.read()<<8|Wire.read();                                  
  acc_z = Wire.read()<<8|Wire.read();                                  
  temp = Wire.read()<<8|Wire.read();                                   
  gyro_x = Wire.read()<<8|Wire.read();                                 
  gyro_y = Wire.read()<<8|Wire.read();                                 
  gyro_z = Wire.read()<<8|Wire.read();  
               
}

void cal()
{
  setup_mpu_6050_registers();                                          //Setup the registers of the MPU-6050 
  for (int cal_int = 0; cal_int < 1000 ; cal_int ++){                  //Read the raw acc and gyro data from the MPU-6050 for 1000 times
    read_mpu_6050_data();                                             
    gyro_x_cal += gyro_x;                                              //Add the gyro x offset to the gyro_x_cal variable
    gyro_y_cal += gyro_y;                                              //Add the gyro y offset to the gyro_y_cal variable
    gyro_z_cal += gyro_z; 
    acc_x_cal += acc_x;                                              //Add the acc x offset to the acc_x_cal variable
    acc_y_cal += acc_y;                                              //Add the acc y offset to the acc_y_cal variable
    acc_z_cal += acc_z;//Add the gyro z offset to the gyro_z_cal variable
    delay(3);                                                          //Delay 3us to have 250Hz for-loop
  }

  // divide by 1000 to get avarage offset
  gyro_x_cal /= 1000;                                                 
  gyro_y_cal /= 1000;                                                 
  gyro_z_cal /= 1000;  
  acc_x_cal /= 1000;                                                 
  acc_y_cal /= 1000;                                                 
  acc_z_cal /= 1000;                                                
  loop_timer = micros();                                               //Reset the loop timer
}
void var()
{
  acc_x -= acc_x_cal;                                                
  acc_y -= acc_y_cal;                                                
  acc_z -= acc_z_cal;   
  gyro_x -= gyro_x_cal;                                                
  gyro_y -= gyro_y_cal;                                                
  gyro_z -= gyro_z_cal;
//  Serial.print("acc_x =");
//  Serial.print(acc_x);
//  Serial.print(" acc_y =");
//  Serial.print(acc_y);               
//  Serial.print(" acc_z =");  
//  Serial.print(acc_z);  
//  Serial.print("gyro_x =");  
//  Serial.print(gyro_x);
//  Serial.print("gyro_y =");  
//  Serial.print(gyro_y);  
//  Serial.print("gyro_z =");  
//  Serial.println(gyro_z);        
}

