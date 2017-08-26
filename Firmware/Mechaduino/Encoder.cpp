#include "Encoder.h"
#include <SPI.h>
#include "State.h"
#include "Configuration.h"
#include "Configurationals.h"
#include "State.h"
#include "Utils.h"

int readEncoder() {

  REG_PORT_OUTCLR1 = PORT_PB09;  // write chipSelectPin LOW
  SPI.transfer(0x3F);
  SPI.transfer(0xFF);

  REG_PORT_OUTSET1 = PORT_PB09;  // write chipSelectPin HIGH

  delayMicroseconds(1);

  REG_PORT_OUTCLR1 = PORT_PB09;  // write chipSelectPin LOW
  byte hibyte = SPI.transfer(0x3F);
  byte lobyte = SPI.transfer(0xFF);
  REG_PORT_OUTSET1 = PORT_PB09;  // write chipSelectPin HIGH

  return (((hibyte << 8) | lobyte) & 0B0011111111111111);

}







int readAngle() {
  int32_t temp_angle;

  REG_PORT_OUTCLR1 = PORT_PB09;  // write chipSelectPin LOW
  SPI.transfer(0x3F);
  SPI.transfer(0xFF);

  REG_PORT_OUTSET1 = PORT_PB09;  // write chipSelectPin HIGH

  delayMicroseconds(1);

  REG_PORT_OUTCLR1 = PORT_PB09;  // write chipSelectPin LOW
  byte hibyte = SPI.transfer(0x3F);
  byte lobyte = SPI.transfer(0xFF);
  REG_PORT_OUTSET1 = PORT_PB09;  // write chipSelectPin HIGH

  int raw = lookup[(((hibyte << 8) | lobyte) & 0B0011111111111111)];

  int raw_diff = raw  - mod(y,36000);

  if (raw_diff < -18000) {
    temp_angle = y + 36000 + raw_diff;
  }
  else if (raw_diff > 18000) {
    temp_angle = y - 36000 + raw_diff;
  }
  else {
    temp_angle = y  + raw_diff;
  }


  return temp_angle;

}
