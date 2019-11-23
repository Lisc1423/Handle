#ifndef __lcd_func_H
#define __lcd_func_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
#include "ILI93xx.h"


extern float lcd_data[10];
uint8_t * ftoa(double db, uint8_t *str);
void between_A_B();
void handle_show_lcd();
float angle_to360(float angle);
extern float lcd_data[10];
#ifdef __cplusplus
}
#endif
#endif /*__lcd_func_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/