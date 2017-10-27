#ifndef SERDES_H_
#define SERDES_H_
#include <cyu3types.h>

/*Deserializer register address*/
#define DesAddr_Id        0x00 //Deserializer Device ID: 0x60<<1
#define DesAddr_Config0   0x02
#define DesAddr_Config1   0x03
#define DesAddr_EQ        0x04
#define DesAddr_LF_Gain   0x05
#define DesAddr_Ser_ID    0x06
#define DesAddr_Ser_Alias 0x07
#define DesAddr_Slave0_ID 0x08
#define DesAddr_Slave1_ID 0x09
#define DesAddr_Slave2_ID 0x0A
#define DesAddr_Slave3_ID 0x0B
#define DesAddr_Slave4_ID 0x0C
#define DesAddr_Slave5_ID 0x0D
#define DesAddr_Slave6_ID 0x0E
#define DesAddr_Slave7_ID 0x0F
#define DesAddr_Slave0_Alias 0x10
#define DesAddr_Slave1_Alias 0x11
#define DesAddr_Slave2_Alias 0x12
#define DesAddr_Slave3_Alias 0x13
#define DesAddr_Slave4_Alias 0x14
#define DesAddr_Slave5_Alias 0x15
#define DesAddr_Slave6_Alias 0x16
#define DesAddr_Slave7_Alias 0x17
#define DesAddr_Parity0_Err_Th   0x18
#define DesAddr_Parity1_Err_Th   0x19
#define DesAddr_Parity0_Err  0x1A
#define DesAddr_Parity1_Err  0x1B
#define DesAddr_Gen_Status   0x1C
#define DesAddr_Gpio_1_0     0x1D
#define DesAddr_Gpio_3_2     0x1E
#define DesAddr_OSS_Mode     0x1F
#define DesAddr_BCC_WD       0x20
#define DesAddr_I2C_Ctl1     0x21
#define DesAddr_I2C_Ctl2     0x22
#define DesAddr_GPCR         0x23
#define DesAddr_BIST_Ctl     0x24
#define DesAddr_Parity_Err_Cnt   0x25
#define DesAddr_BCC0_Tune   0x26
#define DesAddr_Fwd_Ctl0_Tune     0x27




/*Serializer register*/
#define SerId 0xB0 //Serializer Device ID: 0x58<<1

uint8_t Serdes_init(void)


#endif /* SERDES_H_ */
