#include <stdlib.h>
#include <stdio.h>
#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
                                                                                                                                                

#define VERSION_REQUIRED_MAJOR 1
#define VERSION_REQUIRED_MINOR 0
#define VERSION_REQUIRED_BUILD 1


#define RDEV_I2C_ADDR 0x28
#define LDEV_I2C_ADDR 0x29


#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"


/* Function to print status */
void print_pal_error(VL53L0X_Error Status){
    char buf[VL53L0X_MAX_STRING_LENGTH];
    VL53L0X_GetPalErrorString(Status, buf);
    printf("API Status: %i : %s\n", Status, buf);
}

/* Function to print measurement status */
void print_range_status(VL53L0X_RangingMeasurementData_t* pRangingMeasurementData){
    char buf[VL53L0X_MAX_STRING_LENGTH];
    uint8_t RangeStatus;

    /*
     * New Range Status: data is valid when pRangingMeasurementData->RangeStatus = 0
     */

    RangeStatus = pRangingMeasurementData->RangeStatus;

    VL53L0X_GetRangeStatusString(RangeStatus, buf);
    printf("Range Status: %i : %s\n", RangeStatus, buf);

}

VL53L0X_Error ranging(VL53L0X_Dev_t *pDevice)
{

}

int main(int argc, char** argv) 
{	
	VL53L0X_Error Status = VL53L0X_ERROR_NONE;
	VL53L0X_Dev_t LDevice, RDevice;
	VL53L0X_Dev_t *pLDevice = &LDevice;
	VL53L0X_Dev_t *pRDevice = &RDevice;

 	/*
 	 * Initializing device and api
	 */ 

    pRDevice->I2cDevAddr = RDEV_I2C_ADDR;
	pLDevice->I2cDevAddr = LDEV_I2C_ADDR;

	pRDevice->fd = VL53L0X_i2c_init("/dev/i2c-1", pRDevice->I2cDevAddr);
	pLDevice->fd = VL53L0X_i2c_init("/dev/i2c-1", pLDevice->I2cDevAddr);

	if (RDevice.fd<0) {
		Status = VL53L0X_ERROR_CONTROL_INTERFACE;
	    printf ( LIGHT_RED "Failed to init right device\n " NONE);
		return -1;
	}

	if (LDevice.fd<0) {                                                                                                                         
		Status = VL53L0X_ERROR_CONTROL_INTERFACE;
		printf ( LIGHT_RED "Failed to init left device\n " NONE);
		return -1;
    }

	Status = VL53L0X_DataInit(&LDevice);
	Status = VL53L0X_DataInit(&RDevice);



}
