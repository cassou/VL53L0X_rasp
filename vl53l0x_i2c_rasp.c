#include <stdio.h>

#include "vl53l0x_i2c_platform.h"
#include "vl53l0x_def.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vl53l0x_platform_log.h"

#ifdef VL53L0X_LOG_ENABLE
#define trace_print(level, ...) trace_print_module_function(TRACE_MODULE_PLATFORM, level, TRACE_FUNCTION_NONE, ##__VA_ARGS__)
#define trace_i2c(...) trace_print_module_function(TRACE_MODULE_NONE, TRACE_LEVEL_NONE, TRACE_FUNCTION_I2C, ##__VA_ARGS__)
#endif

int VL53L0X_i2c_init()
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_i2c_close(void)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_write_multi(uint8_t address, uint8_t reg, uint8_t *pdata, int32_t count)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_multi(uint8_t address, uint8_t index, uint8_t *pdata, int32_t count)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_write_byte(uint8_t address, uint8_t index, uint8_t data)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}


int32_t VL53L0X_write_word(uint8_t address, uint8_t index, uint16_t data)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_write_dword(uint8_t address, uint8_t index, uint32_t data)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_byte(uint8_t address, uint8_t index, uint8_t *pdata)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_word(uint8_t address, uint8_t index, uint16_t *pdata)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_dword(uint8_t address, uint8_t index, uint32_t *pdata)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_write_multi16(uint8_t address, uint16_t index, uint8_t *pdata, int32_t count)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_multi16(uint8_t address, uint16_t index, uint8_t *pdata, int32_t count)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_write_byte16(uint8_t address, uint16_t index, uint8_t data)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}


int32_t VL53L0X_write_word16(uint8_t address, uint16_t index, uint16_t data)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_write_dword16(uint8_t address, uint16_t index, uint32_t data)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_byte16(uint8_t address, uint16_t index, uint8_t *pdata)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_word16(uint8_t address, uint16_t index, uint16_t *pdata)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_read_dword16(uint8_t address, uint16_t index, uint32_t *pdata)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_platform_wait_us(int32_t wait_us)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_wait_ms(int32_t wait_ms)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_set_gpio(uint8_t level)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_get_gpio(uint8_t *plevel)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_release_gpio(void)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_cycle_power(void)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_get_timer_frequency(int32_t *ptimer_freq_hz)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}

int32_t VL53L0X_get_timer_value(int32_t *ptimer_count)
{
    return VL53L0X_ERROR_NOT_IMPLEMENTED;
}
