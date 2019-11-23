#include "adc_func.h"
#include "nrf24l01.h"
#include "nrf_comm.h"
#include "string.h"

uint32_t ADC_Value[150];
int adc_power_off_flag = 0;

float adc_num = 0;
float adc_power = 0;
Handle chassis_handle = {0,0,0,0};
int16_t handle_rocker[4];

int adc_flag = 0;
struct adc_rocker adc_rocker_value;
void adc_exe()
{
  if(adc_flag == 0) return;
  
  uint16_t adc_data[4];
  
  uint8_t temp[10] = {0};
  
  for(int i = 0; i < 4; i++)
  {
    adc_data[i] = (*((uint16_t *)&adc_rocker_value+1+i)-2048)*256/4096;
  }
  
  memcpy(temp,(uint16_t *)&adc_data,8);
  
  //nrf_send_data(temp, 10);
  
  nrf_handle.nrf_data_from = NRF_SPI;
  nrf_handle.nrf_data_to = NRF_SPI;
  nrf_comm_send(temp, 10);
  
  adc_flag = 0;
}