#ifndef __GPIO_H__
#define __GPIO_H__
 
#ifdef _cplusplus
extern "C"
{
#endif
   
#include "driver/gpio.h"

/*********************** 宏定义区 ***********************/
//类型：I
#define GPIO_CF         GPIO_NUM_36//PIN4- 电量统计
#define GPIO_CF1        GPIO_NUM_37//PIN5- 电压电流检测
#define GPIO_OVER       GPIO_NUM_38//PIN6- 过流检测
#define GPIO_OFF_CHECK  GPIO_NUM_39//PIN7- 异常断电检测
#define GPIO_KEY        GPIO_NUM_34//PIN9- 按键
//类型：I/O
#define GPIO_SEL        GPIO_NUM_25//PIN15-电压电流切换
#define GPIO_LED        GPIO_NUM_26//OIN16-指示灯（配网和继电器状态 复用）
#define GPIO_CTRL       GPIO_NUM_27//PIN17-继电器控制
 
/*********************** enum 区 ************************/
 
/*********************** struct 区 **********************/

/*********************** 函数声明区 *********************/
 /*GPIO初始化*/
void GPIO_LED_INIT(void);
void GPIO_CTRL_INIT(void);
void GPIO_CF1_INIT(void);

void GPIO_OVER_INIT(void);
void GPIO_CF_INIT(void);
void GPIO_SEL_INIT(void);
void GPIO_OFF_CHECK_INIT(void);
void GPIO_KEY_INIT(void);

//void GPIO_INIT(void);



#ifdef _cplusplus
}
#endif
 

#endif