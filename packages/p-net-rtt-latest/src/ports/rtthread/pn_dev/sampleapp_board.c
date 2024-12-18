/*********************************************************************
 *        _       _         _
 *  _ __ | |_  _ | |  __ _ | |__   ___
 * | '__|| __|(_)| | / _` || '_ \ / __|
 * | |   | |_  _ | || (_| || |_) |\__ \
 * |_|    \__|(_)|_| \__,_||_.__/ |___/
 *
 * www.rt-labs.com
 * Copyright 2021 rt-labs AB, Sweden.
 *
 * This software is dual-licensed under GPLv3 and a commercial
 * license. See the file LICENSE.md distributed with this software for
 * full license information.
 ********************************************************************/

#include <rtthread.h>
#include <rtdevice.h>
#include "sampleapp_common.h"

#include "drv_gpio.h"
#include <hal_data.h>

/************************* Utilities ******************************************/

void app_set_led (uint16_t id, bool led_state)
{
   if (id == APP_DATA_LED_ID)
   {
       rt_pin_write(BSP_IO_PORT_14_PIN_1, led_state ? 1 : 0);
   }
   else if (id == APP_PROFINET_SIGNAL_LED_ID)
   {
       rt_pin_write(BSP_IO_PORT_14_PIN_1, led_state ? 1 : 0);
   }
}

bool app_get_button (uint16_t id)
{
    if (id == 0)
    {
        return rt_pin_read(BSP_IO_PORT_14_PIN_2) == 1;
    }
    else if (id == 1)
    {
        /* No more buttons on board */
        return false;
    }
}
