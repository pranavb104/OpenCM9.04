/* Dynamixel Maximum Volatage Example

 This example shows how to use dynamixel as maximum Volatage
 All dynamixels are set as joint mode in factory,
 but if you want to change the maximum Volatage using dynamixel,
 you have to change it to maximum Volatage by maximum Volatage to 80

                   Compatibility
 CM900                  O
 OpenCM9.04             O

                 Dynamixel Compatibility
               AX    MX      RX    XL-320    Pro
 CM900          O      O      O        O      X
 OpenCM9.04     O      O      O        O      X
 **** OpenCM 485 EXP board is needed to use 4 pin Dynamixel and Pro Series ****

 created 22 May 2014
 by ROBOTIS CO,.LTD.
 */
 #include <Dynamixel.h>

 
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

#define ID_NUM 1
#define LIMIT_VOLTAGE_ADDRESS 13
Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup() {
  // Initialize the dynamixel bus:

  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
  Dxl.maxVolt(ID_NUM, 80);     // set maximum input voltage to dxl as 8V
  Dxl.alarmShutdown(ID_NUM, 1);
  Dxl.jointMode(ID_NUM); //jointMode() is to use position mode
}

void loop() {
  Dxl.goalPosition(ID_NUM, 1); //ID 1 dynamixel moves to position 1
  delay(1000);
  Dxl.goalPosition(ID_NUM, 1023); //ID 1 dynamixel moves to position 1023
  delay(1000);
}