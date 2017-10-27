#include <cyu3system.h>
#include <cyu3os.h>
#include <cyu3dma.h>
#include <cyu3error.h>
#include <cyu3uart.h>
#include <cyu3i2c.h>
#include <cyu3types.h>
#include <cyu3gpio.h>
#include <cyu3utils.h>
#include "serdes.h"



typedef struct
{
	uint8_t reg_addr;
	uint8_t	value;
}reg_val;

const reg_val Des_SlaveID[] =
{
	{0x08,0}, //slave ID[0]:device attached to Serializer
	{0x09,0}, //slave ID[1]:device attached to Serializer
	{0x0A,0}, //slave ID[2]:device attached to Serializer
	{0x0B,0}, //slave ID[3]:device attached to Serializer
	{0x0C,0}, //slave ID[4]:device attached to Serializer
	{0x0D,0}, //slave ID[5]:device attached to Serializer
	{0x0E,0}, //slave ID[6]:device attached to Serializer
	{0x0F,0}, //slave ID[7]:device attached to Serializer
};

const reg_val Ser_SlaveID[] =
{
	{0x08,0} //slave ID[0]:device attached to Deserializer
};


/* Write to an I2C slave with two bytes of data. */
CyU3PReturnStatus_t
SerdesWriteB (
        uint8_t slaveAddr,
        uint8_t highAddr,
        uint8_t highData)
{
    CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
    CyU3PI2cPreamble_t  preamble;
    uint8_t buf[1];

    /* Validate the I2C slave address. */
    if ((slaveAddr != i2c_ADDR_WR))
    {
        CyU3PDebugPrint (4, "I2C Slave address is not valid!\n");
        return 1;
    }

    /* Set the parameters for the I2C API access and then call the write API. */
    preamble.buffer[0] = slaveAddr;
    preamble.buffer[1] = highAddr;
    preamble.length    = 2;             /*  Three byte preamble. */
    preamble.ctrlMask  = 0x0000;        /*  No additional start and stop bits. */

    buf[0] = highData;

    apiRetStatus = CyU3PI2cTransmitBytes (&preamble, buf, 1, 0);
    SensorI2CAccessDelay (apiRetStatus);

    return apiRetStatus;
}

CyU3PReturnStatus_t
SerdesReadB (
        uint8_t slaveAddr,
        uint8_t highAddr,
        uint8_t *buf)
{
    CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
    CyU3PI2cPreamble_t preamble;

    if ((slaveAddr != i2c_ADDR_RD))
    {
        CyU3PDebugPrint (4, "I2C Slave address is not valid!\n");
        return 1;
    }

    preamble.buffer[0] = slaveAddr & I2C_SLAVEADDR_MASK;        /*  Mask out the transfer type bit. */
    preamble.buffer[1] = highAddr;
    preamble.buffer[2] = slaveAddr;
    preamble.length    = 3;
    preamble.ctrlMask  = 0x0002;                                /*  Send start bit after 2nd byte of preamble. */

    apiRetStatus = CyU3PI2cReceiveBytes (&preamble, buf, 1, 0);
//    SensorI2CAccessDelay (apiRetStatus);

    return apiRetStatus;
}

uint8_t des_(void)
{

}

uint8_t Serdes_init(void)
{
    /* The sensor ID register can be read here to verify sensor connectivity. */
    uint8_t buf[1];
//    buf[0] = 0x08;
//    if (i2cWriteB (i2c_ADDR_WR, 0x2D, buf[0]) == CY_U3P_SUCCESS) {
//    	CyU3PDebugPrint (4, "write i2c device success! \r\n");
//    } else
//    	CyU3PDebugPrint (4, "write i2c device failure! \r\n");

    /* Reading i2c*/
    if (i2cReadB (i2c_ADDR_RD, 0x32, buf) == CY_U3P_SUCCESS)
    {
    	CyU3PDebugPrint (4, "read i2c data: 0x%x\r\n", buf[0]);
    } else
    	CyU3PDebugPrint (4, "read i2c device failure! \r\n");
    return 1;
}

