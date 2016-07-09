#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <time.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include "vl53l0x_platform.h"
#include "vl53l0x_api.h"

int VL53L0X_i2c_init(char * devPath, int devAddr)
{
    int file;
    if ((file = open(devPath, O_RDWR)) < 0) {
        /* ERROR HANDLING: you can check errno to see what went wrong */
        perror("Failed to open the i2c bus");
        return -1;
    }
    if (ioctl(file, I2C_SLAVE, devAddr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        return -1;
    }
    return file;
}

int32_t VL53L0X_i2c_close(void)
{
    printf("%s\n", __FUNCTION__);
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

static int i2c_write(int fd, uint8_t cmd, uint8_t * data, uint8_t len){

    uint8_t * buf = malloc(len+1);
    buf[0] = cmd;
    memcpy(buf+1, data, len);
    if (write(fd, buf, len+1) != len+1) {
        printf("Failed to write to the i2c bus.\n");
        free(buf);
        return VL53L0X_ERROR_CONTROL_INTERFACE;
    }
    free(buf);
    return VL53L0X_ERROR_NONE;
}

static int i2c_read(int fd, uint8_t cmd, uint8_t * data, uint8_t len){

    if (write(fd, &cmd, 1) != 1) {
        printf("Failed to write to the i2c bus.\n");
        return VL53L0X_ERROR_CONTROL_INTERFACE;
    }

    if (read(fd, data, len) != len) {
        printf("Failed to read from the i2c bus.\n");
        return VL53L0X_ERROR_CONTROL_INTERFACE;
    }

    return VL53L0X_ERROR_NONE;
}

VL53L0X_Error VL53L0X_LockSequenceAccess(VL53L0X_DEV Dev){
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    return Status;
}

VL53L0X_Error VL53L0X_UnlockSequenceAccess(VL53L0X_DEV Dev){
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    return Status;
}

VL53L0X_Error VL53L0X_WriteMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count){
    return i2c_write(Dev->fd, index, pdata, count);
}

VL53L0X_Error VL53L0X_ReadMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count){
    return i2c_read(Dev->fd, index, pdata, count);
}

VL53L0X_Error VL53L0X_WrByte(VL53L0X_DEV Dev, uint8_t index, uint8_t data){
	return i2c_write(Dev->fd, index, &data, 1);
}

VL53L0X_Error VL53L0X_WrWord(VL53L0X_DEV Dev, uint8_t index, uint16_t data){
    uint8_t buf[4];
    buf[1] = data>>0&0xFF;
    buf[0] = data>>8&0xFF;
    return i2c_write(Dev->fd, index, buf, 2);
}

VL53L0X_Error VL53L0X_WrDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t data){
    uint8_t buf[4];
    buf[3] = data>>0&0xFF;
    buf[2] = data>>8&0xFF;
    buf[1] = data>>16&0xFF;
    buf[0] = data>>24&0xFF;
    return i2c_write(Dev->fd, index, buf, 4);
}

VL53L0X_Error VL53L0X_UpdateByte(VL53L0X_DEV Dev, uint8_t index, uint8_t AndData, uint8_t OrData){

    int32_t status_int;
    uint8_t data;

    status_int = i2c_read(Dev->fd, index, &data, 1);

    if (status_int != 0){
        return  status_int;
    }

    data = (data & AndData) | OrData;
    return i2c_write(Dev->fd, index, &data, 1);
}

VL53L0X_Error VL53L0X_RdByte(VL53L0X_DEV Dev, uint8_t index, uint8_t *data){
    uint8_t tmp = 0;
    int ret = i2c_read(Dev->fd, index, &tmp, 1);
    *data = tmp;
    // printf("%u\n", tmp);
    return ret;
}

VL53L0X_Error VL53L0X_RdWord(VL53L0X_DEV Dev, uint8_t index, uint16_t *data){
    uint8_t buf[2];
    int ret = i2c_read(Dev->fd, index, buf, 2);
    uint16_t tmp = 0;
    tmp |= buf[1]<<0;
    tmp |= buf[0]<<8;
    // printf("%u\n", tmp);
    *data = tmp;
    return ret;
}

VL53L0X_Error  VL53L0X_RdDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t *data){
    uint8_t buf[4];
    int ret = i2c_read(Dev->fd, index, buf, 4);
    uint32_t tmp = 0;
    tmp |= buf[3]<<0;
    tmp |= buf[2]<<8;
    tmp |= buf[1]<<16;
    tmp |= buf[0]<<24;
    *data = tmp;
    // printf("%zu\n", tmp);
    return ret;
}

VL53L0X_Error VL53L0X_PollingDelay(VL53L0X_DEV Dev){
    usleep(5000);
    return VL53L0X_ERROR_NONE;
}
