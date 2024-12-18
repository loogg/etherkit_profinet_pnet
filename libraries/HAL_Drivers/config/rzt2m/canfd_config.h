/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2021-10-29     mazhiyuan         first version
 */

#ifndef __CAN_CONFIG_H__
#define __CAN_CONFIG_H__

#include <rtthread.h>
#include "hal_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(BSP_USING_CANFD0)
#ifndef CANFD0_CONFIG
#define CANFD0_CONFIG                 \
    {                                 \
        .name = "canfd0",             \
        .num_of_mailboxs = 48,        \
        .p_api_ctrl = &g_canfd0_ctrl, \
        .p_cfg = &g_canfd0_cfg,       \
    }
#endif /* CAN0_CONFIG */
#endif /* BSP_USING_CANFD0 */

#if defined(BSP_USING_CANFD1)
#ifndef CANFD1_CONFIG
#define CANFD1_CONFIG                 \
    {                                 \
        .name = "canfd1",             \
        .num_of_mailboxs = 48,        \
        .p_api_ctrl = &g_canfd1_ctrl, \
        .p_cfg = &g_canfd1_cfg,       \
    }
#endif /* CAN1_CONFIG */
#endif /* BSP_USING_CANFD1 */

#ifdef __cplusplus
}
#endif
#endif
