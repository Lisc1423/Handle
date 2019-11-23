#include "main.h"
#include "lcd_func.h"
#include "string.h"

float lcd_data[10]={0};
float b[3];
float bupt[3] = {0}; 
float action[3]={0};
float error[3]={0};
float buptangle= 0;

void handle_show_lcd()
{
  //angle x y
  action[0] = lcd_data[3];
  action[1] = lcd_data[4];
  action[2] = lcd_data[5]; 
  
  b[0] = lcd_data[0];
  b[1] = lcd_data[1];
  b[2] = angle_to360(lcd_data[2]);
  
  bupt[0] = lcd_data[0];
  bupt[1] = lcd_data[1];
  buptangle = lcd_data[2];  
  bupt[2] = angle_to360(lcd_data[2]);
  

  
  between_A_B();

  LCD_ShowFloat(30,60,80,80,24,bupt[0]);
  LCD_ShowFloat(30,160,80,80,24,bupt[1]);
  LCD_ShowFloat(30,260,80,80,24,bupt[2]);
  LCD_ShowFloat(130,60,80,80,24,action[0]);
  LCD_ShowFloat(130,160,80,80,24,action[1]);
  LCD_ShowFloat(130,260,80,80,24,action[2]);
  LCD_ShowFloat(230,60,80,80,24,error[0]);
  LCD_ShowFloat(230,160,80,80,24,error[1]);
  LCD_ShowFloat(230,260,80,80,24,error[2]);
  LCD_ShowString(30,360,70,12,24,"Angle");
  LCD_ShowFloat(30,400,180,80,24,buptangle);
}
void between_A_B()
{
  LCD_DrawRectangle(2,2,317,477); //边框
  LCD_DrawLine(20,2,20,352);      //列线
  LCD_DrawLine(120,2,120,352);
  LCD_DrawLine(220,2,220,352);  
  LCD_DrawLine(2,52,317,52);      //行线
  LCD_DrawLine(2,152,317,152);
  LCD_DrawLine(2,252,317,252);
  LCD_DrawLine(2,352,317,352);
  LCD_ShowString(6,90,12,12,24,"A");//列标
  LCD_ShowString(6,190,12,12,24,"X");
  LCD_ShowString(6,290,12,12,24,"Y");
  LCD_ShowString(50,12,70,12,24,"BUPT");//行标
  LCD_ShowString(140,12,70,12,24,"ACTION");
  LCD_ShowString(250,12,70,12,24,"B-A");
  LCD_ShowString(10,465,40,12,12,"Bupt");
  //LCD_ShowFloat(260,465,20,10,12,system_time);
  LCD_ShowNum(260,465,system_time , 8 , 12);  	
}

float angle_to360(float angle)
{
  float showangle=0;
  showangle=angle;
  while(showangle>=180||showangle<-180)
  {
    if(showangle>180)showangle-=360;
    if(showangle<=-180)showangle+=360;
  }
  return showangle;
}