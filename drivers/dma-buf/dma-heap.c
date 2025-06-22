
// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/dma-heap.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>

#include "heap-helpers.h"

static int dma_heap_open(struct inode *inode, struct file *file)
{
    return 0;
}

static const struct file_operations dma_heap_fops = {
    .owner = THIS_MODULE,
    .open = dma_heap_open,
};

static int dma_heap_dev_init(void)
{
    int ret;

    ret = dma_heap_add("system", &system_heap_ops);
    if (ret)
        pr_err("Failed to register system dma heap
");

    return ret;
}

module_init(dma_heap_dev_init);
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("DMA Heap Framework");
