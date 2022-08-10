#include "function.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "GPIO.h"
/*LED*/
void GPIO_LED_INIT(void)
{
    gpio_config_t led_conf; 

    led_conf.mode = GPIO_MODE_OUTPUT;		     // 配置gpio的模式
    led_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    led_conf.pin_bit_mask = (1ULL << GPIO_LED);  // 配置GPIO_IN寄存器
    led_conf.pull_down_en = 0;                   // 下拉失能
    led_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&led_conf);                      // 配置gpio参数，并使能

    // 设置gpio输出低电平：
    gpio_set_level(GPIO_LED, 0);
}
/*电压电流检测*/
void GPIO_CF1_INIT(void)
{
    gpio_config_t cf1_conf; 

    cf1_conf.mode = GPIO_MODE_OUTPUT;		 // 配置gpio的模式
    cf1_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    cf1_conf.pin_bit_mask = (1ULL << GPIO_CF1);   // 配置GPIO_IN寄存器
    cf1_conf.pull_down_en = 0;                   // 下拉失能
    cf1_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&cf1_conf);                      // 配置gpio参数，并使能

}
/*电量统计*/
void GPIO_CF_INIT(void)
{
    gpio_config_t cf_conf; 

    cf_conf.mode = GPIO_MODE_OUTPUT;		     // 配置gpio的模式
    cf_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    cf_conf.pin_bit_mask = (1ULL << GPIO_CF);    // 配置GPIO_IN寄存器
    cf_conf.pull_down_en = 0;                   // 下拉失能
    cf_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&cf_conf);                      // 配置gpio参数，并使能
}
/*过零检测*/
void GPIO_OVER_INIT(void)
{
    gpio_config_t over_conf; 

    over_conf.mode = GPIO_MODE_OUTPUT;		     // 配置gpio的模式
    over_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    over_conf.pin_bit_mask = (1ULL << GPIO_OVER);  // 配置GPIO_IN寄存器
    over_conf.pull_down_en = 0;                   // 下拉失能
    over_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&over_conf);                      // 配置gpio参数，并使能

    // 设置gpio为低电平：
    gpio_set_level(GPIO_OVER, 0);
}
/*电压电流切换*/
void GPIO_SEL_INIT(void)
{
    gpio_config_t sel_conf; 

    sel_conf.mode = GPIO_MODE_OUTPUT;		     // 配置gpio的模式
    sel_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    sel_conf.pin_bit_mask = (1ULL << GPIO_SEL);   // 配置GPIO_IN寄存器
    sel_conf.pull_down_en = 1;                   // 下拉,优先低电平
    sel_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&sel_conf);                      // 配置gpio参数，并使能

}
/*继电器控制*/
void GPIO_CTRL_INIT(void)
{
    gpio_config_t sel_conf; 

    sel_conf.mode = GPIO_MODE_OUTPUT;		     // 配置gpio的模式
    sel_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    sel_conf.pin_bit_mask = (1ULL << GPIO_CTRL);   // 配置GPIO_IN寄存器
    sel_conf.pull_down_en = 0;                   // 下拉失能
    sel_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&sel_conf);                      // 配置gpio参数，并使能

    // 设置gpio为低电平：
    gpio_set_level(GPIO_CTRL, 0);
}
/*异常断电检测*/
void GPIO_OFF_CHECK_INIT(void)
{
    gpio_config_t sel_conf; 

    sel_conf.mode = GPIO_MODE_INPUT;		     // 配置gpio的模式
    sel_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    sel_conf.pin_bit_mask = (1ULL << GPIO_OFF_CHECK);   // 配置GPIO_IN寄存器
    sel_conf.pull_down_en = 0;                   // 下拉失能
    sel_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&sel_conf);                      // 配置gpio参数，并使能

    // 设置gpio为低电平：
    gpio_set_level(GPIO_OFF_CHECK, 0);
}
/*按键*/
void GPIO_KEY_INIT(void)
{
    gpio_config_t sel_conf; 

    sel_conf.mode = GPIO_MODE_INPUT;		     // 配置gpio的模式
    sel_conf.intr_type = GPIO_PIN_INTR_DISABLE;  // 失能中断 
    sel_conf.pin_bit_mask = (1ULL << GPIO_KEY);   // 配置GPIO_IN寄存器
    sel_conf.pull_down_en = 0;                   // 下拉使能
    sel_conf.pull_up_en = 0;                     // 上拉失能

    gpio_config(&sel_conf);                      // 配置gpio参数，并使能
}

/*继电器开*/
void relay_on()
{
    gpio_pad_select_gpio(GPIO_CTRL);                // 选择一个GPIO
    gpio_set_direction(GPIO_CTRL, GPIO_MODE_OUTPUT);// 把这个GPIO作为输出
    gpio_set_level(GPIO_CTRL, 1); 
    vTaskDelay(10);
}
/*继电器关*/
void relay_off()
{
    gpio_pad_select_gpio(GPIO_CTRL);                // 选择一个GPIO
    gpio_set_direction(GPIO_CTRL, GPIO_MODE_OUTPUT);// 把这个GPIO作为输出
    gpio_set_level(GPIO_CTRL, 0);
    vTaskDelay(10);
}


