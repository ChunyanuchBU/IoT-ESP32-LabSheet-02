    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;

    uint8_t LEDIO1[8] = { 23, 22, 1, 3 };
    uint8_t LEDIO2[8] = { 5, 18, 19, 21 };

    void app_main(void)
    {
        for (uint8_t i = 0; i < 4; i++)
        {
            gpio_reset_pin(LEDIO1[i]);
            gpio_reset_pin(LEDIO2[i]);
        }

        for (uint8_t i = 0; i < 4; i++)
        {
            gpio_set_direction(LEDIO1[i], GPIO_MODE_OUTPUT);
            gpio_set_direction(LEDIO2[i], GPIO_MODE_OUTPUT);
        }

        while (true)
        {
        	for (uint8_t i = 0; i < 4; i++)
        	{
            gpio_set_level(LEDIO1[i], 1);
            gpio_set_level(LEDIO2[i], 1);
            usleep(ON_time);
            gpio_set_level(LEDIO1[i], 0);
            gpio_set_level(LEDIO2[i], 0);
            usleep(ON_time);
        }
    }
    }
