#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* 可以使用项目配置菜单（idf.py menuconfig）选择要闪烁的GPIO，
   或者您可以编辑以下行并在此处设置一个数字。
*/
#define BLINK_GPIO 2

void app_main(void)
{
    /* 配置BLINK_GPIO引脚的IOMUX寄存器（一些引脚在复位时已经
       被复用为GPIO，但有些默认为其他功能并需要切换到GPIO。
       请参阅技术参考以获取引脚及其默认功能的列表。）
    */
    gpio_reset_pin(BLINK_GPIO);
    /* 将GPIO设置为推挽输出 */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while (1)
    {
        /* 熄灭LED（输出低电平）*/
        printf("关闭LED\n");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        /* 点亮LED（输出高电平）*/
        printf("打开LED\n");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
