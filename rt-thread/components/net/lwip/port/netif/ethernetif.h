/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-02-22     xiangxistu integrate v1.4.1 v2.0.3 and v2.1.2 porting layer
 */

#ifndef __NETIF_ETHERNETIF_H__
#define __NETIF_ETHERNETIF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lwip/netif.h"
#include <rtthread.h>

#define NIOCTL_GADDR        0x01
#ifndef RT_LWIP_ETH_MTU
#define ETHERNET_MTU        1500
#else
#define ETHERNET_MTU        RT_LWIP_ETH_MTU
#endif

#define ETH_VITRUAL_NETIF_MAX_NUM 6

/* eth flag with auto_linkup or phy_linkup */
#define ETHIF_LINK_AUTOUP   0x0000
#define ETHIF_LINK_PHYUP    0x0100

struct eth_device_config {
    uint8_t virtual_num;

    ip_addr_t ip[ETH_VITRUAL_NETIF_MAX_NUM + 1];
    ip_addr_t netmask[ETH_VITRUAL_NETIF_MAX_NUM + 1];
    ip_addr_t gw[ETH_VITRUAL_NETIF_MAX_NUM + 1];
};

struct eth_device
{
    /* inherit from rt_device */
    struct rt_device parent;

    /* network interface for lwip */
    struct netif *netif;

    rt_uint16_t flags;
    rt_uint8_t  link_changed;
    rt_uint8_t  link_status;
    rt_uint8_t  rx_notice;

    struct rt_spinlock spinlock;
    struct eth_device_config config;
    struct netif* virt_netif[ETH_VITRUAL_NETIF_MAX_NUM];

    /* eth device interface */
    struct pbuf* (*eth_rx)(rt_device_t dev);
    rt_err_t (*eth_tx)(rt_device_t dev, struct pbuf* p);
};
extern struct eth_device *ra_eth_dev;

int eth_system_device_init(void);
void eth_device_deinit(struct eth_device *dev);
rt_err_t eth_device_ready(struct eth_device* dev);
rt_err_t eth_device_init(struct eth_device * dev, const char *name, struct eth_device_config *config);
rt_err_t eth_device_init_with_flag(struct eth_device *dev, const char *name, rt_uint16_t flag, uint8_t ifidx);
rt_err_t eth_device_linkchange(struct eth_device* dev, rt_bool_t up);

#ifdef __cplusplus
}
#endif

#endif /* __NETIF_ETHERNETIF_H__ */
