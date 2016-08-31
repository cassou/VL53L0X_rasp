#include <stdlib.h>                                                                                                                             
#include <stdio.h>
#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"

#define DEF_I2C_ADDR  0x29
#define DEV1_I2C_ADDR 0x28
#define DEV2_I2C_ADDR 0x29

void print_pal_error(VL53L0X_Error Status){
    char buf[VL53L0X_MAX_STRING_LENGTH];
    VL53L0X_GetPalErrorString(Status, buf);
    printf("API Status: %i : %s\n", Status, buf);
}

int main(int argc, char **argv) {
	VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    VL53L0X_Dev_t MyDevice;
    VL53L0X_Dev_t *pMyDevice = &MyDevice;
	
	pMyDevice->I2cDevAddr = DEF_I2C_ADDR;
	pMyDevice->fd = VL53L0X_i2c_init("/dev/i2c-1", pMyDevice->I2cDevAddr);
	Status = VL53L0X_DataInit(&MyDevice);
	Status = VL53L0X_SetDeviceAddress(&MyDevice, DEV1_I2C_ADDR*2);
	pMyDevice->I2cDevAddr   = DEV1_I2C_ADDR;
    pMyDevice->fd = VL53L0X_i2c_init("/dev/i2c-1", pMyDevice->I2cDevAddr);
	Status = VL53L0X_DataInit(&MyDevice);
	
	if(Status == VL53L0X_ERROR_NONE)
    {
			printf("\nSuccess! Address has change to 0x28\n");
    } else {
		printf("\nError!!!!\n");
	}
}
